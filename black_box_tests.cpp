//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Red-Black Tree - public interface tests
//
// $NoKeywords: $ivs_project_1 $black_box_tests.cpp
// $Author:     ALEKSANDR VEREVKIN <xverev00@stud.fit.vutbr.cz>
// $Date:       $2021-03-11
//============================================================================//
/**
* @file black_box_tests.cpp
* @author ALEKSANDR VEREVKIN
*
* @brief Implementace testu binarniho stromu.
*/

#include <vector>

#include "gtest/gtest.h"

#include "red_black_tree.h"

class EmptyTree : public ::testing::Test        //define empty tree
{
protected:
	BinaryTree tree;
};

class NonEmptyTree : public ::testing::Test     //define nonemptytree
{
protected:
	virtual void SetUp() {          //dosadime hodnoty na zacatku
		int values[14] = { 1, 5, 13, 25, 30, 47, 50, 72, 0, 100, -1, -77, 228, 1000 };
		for (auto value : values) {
			tree.InsertNode(value);
		}
	}
	int nums[14] = { 1, 5, 13, 25, 30, 47, 50, 72, 0, 100, -1, -77, 228, 1000 };
	BinaryTree tree;
};

class TreeAxioms : public ::testing::Test       //define tree pro axiomy
{
protected:
	int nums[14] = { 1, 5, 13, 25, 30, 47, 50, 72, 0, 100, -1, -77, 228, 1000 };
	BinaryTree tree;

};

TEST_F(EmptyTree, InsertNode) {

	auto black = BinaryTree::BLACK;         //define barvy
	auto red = BinaryTree::RED;

	EXPECT_TRUE(tree.GetRoot() == NULL);    //test pro empty tree

	auto test1 = tree.InsertNode(2);        //dosadime prvni node
	ASSERT_TRUE(test1.second != NULL);
	EXPECT_TRUE(test1.first);
	EXPECT_EQ(test1.second->key, 2);
	EXPECT_EQ(test1.second->color, black);
	EXPECT_TRUE(test1.second->pParent == NULL);
	EXPECT_TRUE(test1.second->pLeft != NULL);
	EXPECT_TRUE(test1.second->pRight != NULL);
	EXPECT_EQ(test1.second->pLeft->color, black);
	EXPECT_EQ(test1.second->pRight->color, black);
	EXPECT_EQ(test1.second->pLeft->pParent->key, test1.second->key);
	EXPECT_EQ(test1.second->pRight->pParent->key, test1.second->key);

	auto same1 = tree.InsertNode(2);        //dosadime stejny node
	EXPECT_FALSE(same1.first);
	EXPECT_EQ(test1.second, same1.second);

	auto test2 = tree.InsertNode(3);        //dosadime druhy node
	ASSERT_TRUE(test2.second != NULL);
	EXPECT_TRUE(test2.first);
	EXPECT_EQ(test2.second->key, 3);
	EXPECT_EQ(test2.second->color, red);
	EXPECT_TRUE(test2.second->pParent != NULL);
	EXPECT_TRUE(test2.second->pLeft != NULL);
	EXPECT_TRUE(test2.second->pRight != NULL);
	EXPECT_EQ(test2.second->pLeft->color, black);
	EXPECT_EQ(test2.second->pRight->color, black);
	EXPECT_EQ(test2.second->pLeft->pParent->key, test2.second->key);
	EXPECT_EQ(test2.second->pRight->pParent->key, test2.second->key);

	EXPECT_EQ(test2.second->pParent->key, 2);       //test pro relationsheep mezi prvnim a druhem nodes
	EXPECT_EQ(test1.second->pRight->key, 3);

}

TEST_F(EmptyTree, DeleteNode) {
	EXPECT_TRUE(tree.GetRoot() == NULL);    //test pro empty tree

	int values[10] = { 5, 10, 16, 20, 35, 78, 100, 335, 0, -7 };    //odstraneni neexistujucih nodes
	for (int num = 0; num < 10; num++) {
		EXPECT_FALSE(tree.DeleteNode(values[num]));
	}
}

TEST_F(EmptyTree, FindNode) {
	EXPECT_TRUE(tree.GetRoot() == NULL);    //test pro empty tree

	int values[10] = { 1, 4, 10, 35, 50, 76, 100, 240, 0, -3 };     //hledani neexistujucih nodes
	for (int num = 0; num < 10; num++) {
		EXPECT_TRUE(tree.FindNode(values[num]) == NULL);
	}
}

TEST_F(NonEmptyTree, InsertNode) {
	EXPECT_TRUE(tree.GetRoot() != NULL);    //test pro not empty tree

	auto black = BinaryTree::BLACK;         //define barvy
	auto red = BinaryTree::RED;

	auto test1 = tree.InsertNode(27);       //pridame novy node
	ASSERT_TRUE(test1.second != NULL);
	EXPECT_TRUE(test1.first);
	EXPECT_EQ(test1.second->color, red);
	EXPECT_EQ(test1.second->pParent->color, black);
	EXPECT_EQ(test1.second->key, 27);
	EXPECT_TRUE(test1.second->pParent != NULL);
	EXPECT_TRUE(test1.second->pLeft != NULL);
	EXPECT_TRUE(test1.second->pRight != NULL);
	EXPECT_EQ(test1.second->pLeft->color, black);
	EXPECT_EQ(test1.second->pRight->color, black);
	EXPECT_EQ(test1.second->pLeft->pParent->key, test1.second->key);
	EXPECT_EQ(test1.second->pRight->pParent->key, test1.second->key);

	auto same1 = tree.InsertNode(72);       //pridani uz existujuciho node
	EXPECT_FALSE(same1.first);
	EXPECT_EQ(same1.second->key, 72);

}

TEST_F(NonEmptyTree, DeleteNode) {
	EXPECT_TRUE(tree.GetRoot() != NULL);    //test pro not empty tree

	EXPECT_TRUE(tree.DeleteNode(72));       //pokus odstraneni 2 existing a 1 not existing nodes
	EXPECT_TRUE(tree.DeleteNode(50));
	EXPECT_FALSE(tree.DeleteNode(3));

	for (auto num : nums) {                   //odstraneni vsechnich ostatnich existujucih nodes
		if (num == 50 || num == 72) {
			EXPECT_FALSE(tree.DeleteNode(num));
		}
		else {
			EXPECT_TRUE(tree.DeleteNode(num));
		}
	}
}

TEST_F(NonEmptyTree, FindNode) {
	EXPECT_TRUE(tree.GetRoot() != NULL);    //test pro not empty tree

	EXPECT_TRUE(tree.FindNode(72) != NULL);         //pokus najit 2 existing a 1 not existing nodes
	EXPECT_TRUE(tree.FindNode(50) != NULL);
	EXPECT_TRUE(tree.FindNode(3) == NULL);

	for (auto num : nums) {           //pokus najit vsechny existujuci nodes
		EXPECT_TRUE(tree.FindNode(num) != NULL);
	}
}

TEST_F(TreeAxioms, Axiom1) {
	auto black = BinaryTree::BLACK;         //define barvy

	for (auto num : nums) {          //pridani nodes, a overovani jestli leaf nodes are still black
		tree.InsertNode(num);
		std::vector<Node_t *> nodes;
		tree.GetLeafNodes(nodes);
		for (auto node : nodes) {
			EXPECT_TRUE(node->pRight == NULL);
			EXPECT_TRUE(node->pLeft == NULL);
			EXPECT_EQ(node->color, black);
		}
	}
}

TEST_F(TreeAxioms, Axiom2) {

	auto black = BinaryTree::BLACK;         //define barvy
	auto red = BinaryTree::RED;

	for (auto num : nums) {                 //pridani nodes, a overovani jestli nodes are both black
		tree.InsertNode(num);
		std::vector<Node_t *> nodes;
		tree.GetAllNodes(nodes);
		for (auto node : nodes) {
			if (node->color == red) {
				EXPECT_EQ(node->pRight->color, black);
				EXPECT_EQ(node->pLeft->color, black);
			}
		}
	}
}

TEST_F(TreeAxioms, Axiom3) {
	auto black = BinaryTree::BLACK;         //define barvy
	auto red = BinaryTree::RED;

	for (auto num : nums) {          //pridani cisel do tree a overovani jestli delka drah od leafs do root ma stejna cisla black nodes
		tree.InsertNode(num);
		std::vector<Node_t *> nodes;
		tree.GetLeafNodes(nodes);
		int black_nodes = -1;
		for (auto node : nodes) {
			int blackNodes = 0;
			auto myNode = node;
			while (myNode != NULL) {
				if (myNode->color == black) {
					blackNodes++;
				}
				myNode = myNode->pParent;
			}
			if (black_nodes != -1) {
				EXPECT_EQ(black_nodes, blackNodes);
			}
			black_nodes = blackNodes;

		}
	}
}

/*** Konec souboru black_box_tests.cpp ***/
