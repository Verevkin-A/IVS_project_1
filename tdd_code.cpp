//======== Copyright (c) 2021, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Test Driven Development - priority queue code
//
// $NoKeywords: $ivs_project_1 $tdd_code.cpp
// $Author:     ALEKSANDR VEREVKIN <xverev00@stud.fit.vutbr.cz>
// $Date:       $2021-03-11
//============================================================================//
/**
* @file tdd_code.cpp
* @author ALEKSANDR VEREVKIN
*
* @brief Implementace metod tridy prioritni fronty.
*/

#include <stdlib.h>
#include <stdio.h>

#include "tdd_code.h"

PriorityQueue::PriorityQueue()
{
	m_pHead = nullptr;      //konstruktor
}

PriorityQueue::~PriorityQueue()
{
	Element_t *elem = m_pHead;      //destruktor
	while (elem != nullptr) {
		Element_t *act = elem;
		delete act;
		elem = elem->pNext;
	}
}

void PriorityQueue::Insert(int value)
{
	if (m_pHead == nullptr) {                 //vlozeni prvku jako root, pokud fronta prazdna
		m_pHead = new Element_t{
			.pNext = nullptr,
			.value = value
		};
	}
	else if (m_pHead != nullptr && (value > m_pHead->value || value == m_pHead->value)) {     //vlozeni prvku jako root, pokud prvek stejny nebo vetsi nez ostatni
		m_pHead = new Element_t{
			.pNext = m_pHead,
			.value = value
		};
	}
	else if (m_pHead != nullptr && value < m_pHead->value) {          //pokud prvok mensi nez ostatni hledani pozice pro prvek a vlozeni
		Element_t *Last = m_pHead;
		for (Element_t *act = m_pHead; act != nullptr; act = act->pNext) {
			if (act->value < value) {
				Last->pNext = new Element_t{
					.pNext = act,
					.value = value
				};
				break;
			}
			if (act->pNext == nullptr) {
				act->pNext = new Element_t{
					.pNext = nullptr,
					.value = value
				};
				break;
			}
			Last = act;
		}
	}
}

bool PriorityQueue::Remove(int value)
{
	if (Find(value) != NULL) {                //overovani prezence prvku
		Element_t *elem = Find(value);
		if (m_pHead == elem) {
			m_pHead = m_pHead->pNext;
		}
		else {
			Element_t *Last = m_pHead;
			for (Element_t *act = m_pHead; act != nullptr; act = act->pNext) {        //hledani pozice prvku
				if (act == elem) {
					Last->pNext = act->pNext;
					break;
				}
				if (act->pNext == nullptr) {
					Last->pNext = nullptr;
					break;
				}
				Last = act;
			}
		}
		delete elem;
		return true;    //vrati true pokud prvok uspesne odstranen
	}
	else {
		return false;   //vrati false pokud prvok nenalezen
	}
}

PriorityQueue::Element_t *PriorityQueue::Find(int value)
{
	Element_t *elem = m_pHead;
	while (elem != nullptr) {                 //hledani prvku podle hodnoty
		if (elem->value == value) {
			return elem;
		}
		elem = elem->pNext;
	}
	return NULL;                //vrati NULL jestli prvok nenalezen
}

size_t PriorityQueue::Length()
{
	Element_t *elem = m_pHead;
	size_t num = 0;
	while (elem != nullptr) {        //scitani velikosti fronty
		elem = elem->pNext;
		num += 1;
	}
	return num;
}

PriorityQueue::Element_t *PriorityQueue::GetHead()
{
	return m_pHead;     //vrati ukazatel na root prvek
}

/*** Konec souboru tdd_code.cpp ***/
