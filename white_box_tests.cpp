//======== Copyright (c) 2021, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     White Box - Tests suite
//
// $NoKeywords: $ivs_project_1 $white_box_code.cpp
// $Author:     ALEKSANDR VEREVKIN <xverev00@stud.fit.vutbr.cz>
// $Date:       $2021-01-11
//============================================================================//
/**
* @file white_box_tests.cpp
* @author ALEKSANDR VEREVKIN
*
* @brief Implementace testu prace s maticemi.
*/

#include "gtest/gtest.h"
#include "white_box_code.h"

class MATICE_TEST : public ::testing::Test {
protected:
	Matrix matrix;
};

TEST_F(MATICE_TEST, MATRIX_KONSTRUKTOR) {
	EXPECT_NO_THROW(Matrix());
	EXPECT_ANY_THROW(Matrix(0, 0));
	EXPECT_ANY_THROW(Matrix(0, 1));
	EXPECT_NO_THROW(Matrix(1, 1));
	EXPECT_NO_THROW(Matrix(1, 2));
	EXPECT_NO_THROW(Matrix(2, 1));
	EXPECT_NO_THROW(Matrix(5, 5));
	EXPECT_NO_THROW(Matrix(10, 10));
	EXPECT_NO_THROW(Matrix(14, 37));
	EXPECT_NO_THROW(Matrix(50, 50));
	EXPECT_NO_THROW(Matrix(77, 87));
	EXPECT_NO_THROW(Matrix(100, 100));
	EXPECT_NO_THROW(Matrix(500, 500));
	EXPECT_NO_THROW(Matrix(1000, 1000));
	EXPECT_ANY_THROW(Matrix(0, 5));
	EXPECT_ANY_THROW(Matrix(15, 0));
}

TEST_F(MATICE_TEST, MATRIX_SET) {
	matrix = Matrix();                      //konstrukt a test 1 1 matrix
	EXPECT_TRUE(matrix.set(0, 0, 1));
	EXPECT_TRUE(matrix.set(0, 0, 100));
	EXPECT_TRUE(matrix.set(0, 0, -1));
	EXPECT_FALSE(matrix.set(0, 1, 2));
	EXPECT_FALSE(matrix.set(1, 0, 3));
	EXPECT_FALSE(matrix.set(16, 12, 4));

	matrix = Matrix(3, 3);                  //konstrukt a test 3 3 matrix
	EXPECT_TRUE(matrix.set(0, 0, 1337));
	EXPECT_TRUE(matrix.set(2, 2, 88));
	EXPECT_TRUE(matrix.set(0, 2, -10));
	EXPECT_FALSE(matrix.set(3, 3, 3));
	EXPECT_FALSE(matrix.set(100, 0, 2));
	EXPECT_FALSE(matrix.set(2, 7, 10));

	matrix = Matrix(5, 10);                 //konstrukt a test 5 10 matrix
	EXPECT_TRUE(matrix.set(3, 2, 4));
	EXPECT_TRUE(matrix.set(0, 0, 55));
	EXPECT_TRUE(matrix.set(4, 9, -1));
	EXPECT_FALSE(matrix.set(5, 10, 67));
	EXPECT_FALSE(matrix.set(100, 100, 0));
	EXPECT_FALSE(matrix.set(7, 7, 11));

	matrix = Matrix(8, 3);                  //konstrukt a test 8 3 matrix
	EXPECT_TRUE(matrix.set(0, 0, 123));
	EXPECT_TRUE(matrix.set(3, 2, 33));
	EXPECT_TRUE(matrix.set(7, 2, -14));
	EXPECT_FALSE(matrix.set(8, 3, 10000));
	EXPECT_FALSE(matrix.set(374, 1234, -1));
	EXPECT_FALSE(matrix.set(1, 13, 76));

	matrix = Matrix(10, 10);                //konstrukt a test 10 10 matrix
	EXPECT_TRUE(matrix.set(3, 2, 4));
	EXPECT_TRUE(matrix.set(0, 0, 55));
	EXPECT_TRUE(matrix.set(9, 9, -1));
	EXPECT_FALSE(matrix.set(10, 10, 10));
	EXPECT_FALSE(matrix.set(27, 1, 10));
	EXPECT_FALSE(matrix.set(1, 27, 10));

	matrix = Matrix(1, 77);                 //konstrukt a test 1 77 matrix
	EXPECT_TRUE(matrix.set(0, 0, -94));
	EXPECT_TRUE(matrix.set(0, 34, 902));
	EXPECT_TRUE(matrix.set(0, 76, 82));
	EXPECT_FALSE(matrix.set(1, 77, 1));
	EXPECT_FALSE(matrix.set(234, 432, 324));
	EXPECT_FALSE(matrix.set(77, 1, 11));

	matrix = Matrix(42, 2);                 //konstrukt a test 42 2 matrix
	EXPECT_TRUE(matrix.set(33, 1, 5));
	EXPECT_TRUE(matrix.set(0, 0, 55));
	EXPECT_TRUE(matrix.set(41, 1, -1));
	EXPECT_FALSE(matrix.set(42, 2, -1));
	EXPECT_FALSE(matrix.set(23, 42, 10));
	EXPECT_FALSE(matrix.set(100, 100, 100));

	matrix = Matrix(100, 100);              //konstrukt a test 100 100 matrix
	EXPECT_TRUE(matrix.set(3, 2, 4));
	EXPECT_TRUE(matrix.set(0, 0, 333));
	EXPECT_TRUE(matrix.set(99, 99, -100));
	EXPECT_FALSE(matrix.set(100, 100, -100));
	EXPECT_FALSE(matrix.set(270, 1, 30));
	EXPECT_FALSE(matrix.set(99, 100, 0));

	matrix = Matrix(1000, 1000);            //konstrukt a test 1000 1000 matrix
	EXPECT_TRUE(matrix.set(0, 0, 65));
	EXPECT_TRUE(matrix.set(324, 625, 5));
	EXPECT_TRUE(matrix.set(999, 999, -91));
	EXPECT_FALSE(matrix.set(1000, 1000, -1000));
	EXPECT_FALSE(matrix.set(2734, 1, 30));
	EXPECT_FALSE(matrix.set(143, 9217, 239));

}

TEST_F(MATICE_TEST, MATRIX_SETS) {
	matrix = Matrix();              //konstrukt a set 1 1 matrix
	EXPECT_TRUE(matrix.set(std::vector<std::vector< double > > { {0}}));
	EXPECT_TRUE(matrix.set(std::vector<std::vector< double > > { {1500.0}}));
	EXPECT_FALSE(matrix.set(std::vector<std::vector< double > > { {100}, { 100 }}));

	matrix = Matrix(3, 3);          //konstrukt a set 3 3 matrix
	EXPECT_TRUE(matrix.set(std::vector<std::vector< double > > { {1, 2, 3}, { 4, 5.5, 6 }, { 7, 8, 9 }}));
	EXPECT_TRUE(matrix.set(std::vector<std::vector< double > > { {33, 44, 55}, { 13, 25, 36 }, { 0, -1, 0 }}));
	EXPECT_FALSE(matrix.set(std::vector<std::vector< double > > { {1000, 1000.2, 0}}));

	matrix = Matrix(1, 3);          //konstrukt a set 1 3 matrix
	EXPECT_TRUE(matrix.set(std::vector<std::vector< double > > { {1, 2, 3}}));
	EXPECT_TRUE(matrix.set(std::vector<std::vector< double > > { {2, 55, 1111.8}}));
	EXPECT_FALSE(matrix.set(std::vector<std::vector< double > > { {-2, -3, 234}, { 2, 3 }, { 3 }, { 2, -324, 1000, 234 }}));

	matrix = Matrix(3, 1);          //konstrukt a set 3 1 matrix
	EXPECT_TRUE(matrix.set(std::vector<std::vector< double > > { {-1}, { 100 }, { 5 }}));
	EXPECT_TRUE(matrix.set(std::vector<std::vector< double > > { {123}, { 1 }, { 10324 }}));
	EXPECT_FALSE(matrix.set(std::vector<std::vector< double > > { {6}, { 0 }, { 63 }, { 23 }}));

	matrix = Matrix(10, 10);        //konstrukt a set 10 10 matrix
	EXPECT_TRUE(matrix.set(std::vector<std::vector< double > > { {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0},
	{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
	{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
	{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
	{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
	{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
	{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
	{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
	{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
	{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }}));
	EXPECT_FALSE(matrix.set(std::vector<std::vector< double > > { {0}}));

}

TEST_F(MATICE_TEST, MATRIX_GET) {
	matrix = Matrix();              //set 1 1 matrix a dostavani hodnot
	EXPECT_EQ(matrix.get(0, 0), 0);
	EXPECT_ANY_THROW(matrix.get(1, 1));
	EXPECT_ANY_THROW(matrix.get(34, 21));

	matrix = Matrix(3, 3);          //set 3 3 matrix a dostavani hodnot
	matrix.set(std::vector<std::vector< double > > { {1, 2, 3}, { 40, -51, 69 }, { 7.0, 8.2, 9.9 }});
	EXPECT_EQ(matrix.get(0, 0), 1);
	EXPECT_EQ(matrix.get(2, 2), 9.9);
	EXPECT_EQ(matrix.get(1, 1), -51);
	EXPECT_NE(matrix.get(1, 2), 75);
	EXPECT_ANY_THROW(matrix.get(3, 3));
	EXPECT_ANY_THROW(matrix.get(77, 88));

}

TEST_F(MATICE_TEST, MATRIX_EQ) {
	Matrix matrix1_1_1 = Matrix();          //set up 3 - 1 1 matrix
	matrix1_1_1.set(0, 0, 77.2);
	Matrix matrix1_1_2 = Matrix();
	matrix1_1_2.set(0, 0, 78.0);
	Matrix matrix1_1_3 = Matrix();
	matrix1_1_3.set(0, 0, 77.2);

	Matrix matrix2_3_1 = Matrix(2, 3);              //set up 3 - 2 2 matrix
	matrix2_3_1.set(std::vector<std::vector< double > > { {12, 1.2, 167}, { -2, 43, -20 }});
	Matrix matrix2_3_2 = Matrix(2, 3);
	matrix2_3_2.set(std::vector<std::vector< double > > { {7, 0.3, -17}, { 3, 17, 120 }});
	Matrix matrix2_3_3 = Matrix(2, 3);
	matrix2_3_3.set(std::vector<std::vector< double > > { {12, 1.2, 167}, { -2, 43, -20 }});

	Matrix matrix4_4_1 = Matrix(4, 4);              //set up 3 - 4 4 matrix
	matrix4_4_1.set(std::vector<std::vector< double > > { {-1, 10.2, 10, 10}, { -20, 20.2, 20, 20 },
	{ -234, -54, 1, 0 }, { 6.0, -45, 2, 1000 }});
	Matrix matrix4_4_2 = Matrix(4, 4);
	matrix4_4_2.set(std::vector<std::vector< double > > { {5, 10.0, 10, 23}, { 1, 0.0, 20, 12 },
	{ -6, 54, -21, 70 }, { 6.9, 123, 15, 999 }});
	Matrix matrix4_4_3 = Matrix(4, 4);
	matrix4_4_3.set(std::vector<std::vector< double > > { {-1, 10.2, 10, 10}, { -20, 20.2, 20, 20 },
	{ -234, -54, 1, 0 }, { 6.0, -45, 2, 1000 }});

	EXPECT_TRUE(matrix1_1_1 == matrix1_1_3);
	EXPECT_FALSE(matrix1_1_1 == matrix1_1_2);
	EXPECT_FALSE(matrix1_1_3 == matrix1_1_2);
	EXPECT_TRUE(matrix2_3_1 == matrix2_3_3);
	EXPECT_FALSE(matrix2_3_1 == matrix2_3_2);
	EXPECT_FALSE(matrix2_3_3 == matrix2_3_2);
	EXPECT_TRUE(matrix4_4_1 == matrix4_4_3);
	EXPECT_FALSE(matrix4_4_1 == matrix4_4_2);
	EXPECT_FALSE(matrix4_4_3 == matrix4_4_2);
	EXPECT_ANY_THROW(matrix1_1_1 == matrix2_3_1);
	EXPECT_ANY_THROW(matrix1_1_3 == matrix4_4_3);
	EXPECT_ANY_THROW(matrix2_3_2 == matrix4_4_2);

}

TEST_F(MATICE_TEST, MATRIX_ADD) {
	Matrix matrix1_1_1 = Matrix();          //set up 2 1 1 matrix a pricitani
	matrix1_1_1.set(0, 0, 333);
	Matrix matrix1_1_2 = Matrix();
	matrix1_1_2.set(0, 0, 667);
	Matrix matrix1_1_EQ = Matrix();
	matrix1_1_EQ.set(0, 0, 1000);

	EXPECT_EQ(matrix1_1_1 + matrix1_1_2, matrix1_1_EQ);

	Matrix matrix2_3_1 = Matrix(2, 3);              //set up 2 matrix 2 3 a pricitani
	matrix2_3_1.set(std::vector<std::vector< double > > { {12, 1.2, 167}, { -2, 43, -20 }});
	Matrix matrix2_3_2 = Matrix(2, 3);
	matrix2_3_2.set(std::vector<std::vector< double > > { {7, 0.3, -17}, { 3, 17, 120 }});
	Matrix matrix2_3_EQ = Matrix(2, 3);
	matrix2_3_EQ.set(std::vector<std::vector< double > > { {19, 1.5, 150}, { 1, 60, 100 }});

	EXPECT_EQ(matrix2_3_1 + matrix2_3_2, matrix2_3_EQ);

	Matrix matrix4_4_1 = Matrix(4, 4);              //set up 2 matrix 4 4 a pricitani
	matrix4_4_1.set(std::vector<std::vector< double > > { {-1, 10.2, 10, 10}, { -20, 20.2, 20, 20 },
	{ -234, -54, 1, 0 }, { 6.0, -45, 2, 1000 }});
	Matrix matrix4_4_2 = Matrix(4, 4);
	matrix4_4_2.set(std::vector<std::vector< double > > { {5, 10.0, 10, 23}, { 1, 0, 20.0, 12 },
	{ -6, 54, -21, 70 }, { 6.9, 123, 15, 999 }});
	Matrix matrix4_4_EQ = Matrix(4, 4);
	matrix4_4_EQ.set(std::vector<std::vector< double > > { {4, 20.2, 20, 33}, { -19, 20.2, 40, 32 },
	{ -240, 0, -20, 70 }, { 12.9, 78, 17, 1999 }});

	EXPECT_EQ(matrix4_4_1 + matrix4_4_2, matrix4_4_EQ);

	EXPECT_ANY_THROW(matrix1_1_EQ + matrix2_3_1);
	EXPECT_ANY_THROW(matrix1_1_2 + matrix4_4_2);
	EXPECT_ANY_THROW(matrix2_3_1 + matrix4_4_1);
	EXPECT_ANY_THROW(matrix2_3_2 + matrix4_4_2);



}

TEST_F(MATICE_TEST, MATRIX_MULTIPLY) {
	Matrix matrix1_1_1 = Matrix();          //set up 2 1 1 matrix a soucin
	matrix1_1_1.set(0, 0, 5);
	Matrix matrix1_1_2 = Matrix();
	matrix1_1_2.set(0, 0, 6);
	Matrix matrix1_1_3 = Matrix();
	matrix1_1_3.set(0, 0, 30);

	Matrix matrix2_3_1 = Matrix(2, 3);              //set up 3 2 a 2 3 matrix a soucin
	matrix2_3_1.set(std::vector<std::vector< double > > { {12, 1, 167}, { -2, 43, -20 }});
	Matrix matrix3_2_1 = Matrix(3, 2);
	matrix3_2_1.set(std::vector<std::vector< double > > { {7, 0}, { 3, 17 }, { -6, 54 }});
	Matrix matrix2_2_1 = Matrix(2, 2);
	matrix2_2_1.set(std::vector<std::vector< double > > { {-915, 9035}, { 235, -349 }});

	Matrix matrix4_4_1 = Matrix(4, 4);              //set up 2 4 4 matrix a soucin
	matrix4_4_1.set(std::vector<std::vector< double > > { {-1, 10, 10, 10}, { -20, 20, 20, 20 },
	{ -234, -54, 1, 0 }, { 6, -45, 2, 1000 }});
	Matrix matrix4_4_2 = Matrix(4, 4);
	matrix4_4_2.set(std::vector<std::vector< double > > { {5, 10, 10, 23}, { 1, 0, 20, 12 },
	{ -6, 54, -21, 70 }, { 6, 123, 15, 999 }});
	Matrix matrix4_4_3 = Matrix(4, 4);
	matrix4_4_3.set(std::vector<std::vector< double > > { {5, 1760, 130, 10787}, { -80, 3340, 80, 21160 },
	{ -1230, -2286, -3441, -5960 }, { 5973, 123168, 14118, 998738 }});

	EXPECT_EQ(matrix1_1_1 * matrix1_1_2, matrix1_1_3);
	EXPECT_EQ(matrix2_3_1 * matrix3_2_1, matrix2_2_1);
	EXPECT_EQ(matrix4_4_1 * matrix4_4_2, matrix4_4_3);
	EXPECT_ANY_THROW(matrix1_1_1 * matrix2_3_1);
	EXPECT_ANY_THROW(matrix1_1_2 * matrix4_4_1);
	EXPECT_ANY_THROW(matrix2_3_1 * matrix2_3_1);
	EXPECT_ANY_THROW(matrix3_2_1 * matrix3_2_1);
	EXPECT_ANY_THROW(matrix3_2_1 * matrix4_4_3);

}

TEST_F(MATICE_TEST, MATRIX_SCALAR) {
	Matrix matrix1_1_1 = Matrix();          //set 1 1 matrix a soucin na product
	matrix1_1_1.set(0, 0, 2);
	Matrix matrix1_1_2 = Matrix();
	matrix1_1_2.set(0, 0, 6);
	Matrix matrix1_1_3 = Matrix();

	EXPECT_EQ(matrix1_1_1 * 3, matrix1_1_2);
	EXPECT_EQ(matrix1_1_1 * 0, matrix1_1_3);

	Matrix matrix2_3_1 = Matrix(2, 3);              //set 2 3 matrix a soucin na product
	matrix2_3_1.set(std::vector<std::vector< double > > { {1, 2, -3}, { 3, 2, -1 }});
	Matrix matrix2_3_2 = Matrix(2, 3);
	matrix2_3_2.set(std::vector<std::vector< double > > { {-2, -4, 6}, { -6, -4, 2 }});
	Matrix matrix2_3_3 = Matrix(2, 3);

	EXPECT_EQ(matrix2_3_1 * -2, matrix2_3_2);
	EXPECT_EQ(matrix2_3_2 * 0, matrix2_3_3);
	EXPECT_EQ(matrix2_3_1 * 0, matrix2_3_3);

	Matrix matrix4_4_1 = Matrix(4, 4);              //set 4 4 matrix a soucin na product
	matrix4_4_1.set(std::vector<std::vector< double > > { {5, 10, 10, 23}, { 1, 0, 20, 12 },
	{ -6, 54, -21, 70 }, { 6, 123, 15, 999 }});
	Matrix matrix4_4_2 = Matrix(4, 4);
	matrix4_4_2.set(std::vector<std::vector< double > > { {30, 60, 60, 138}, { 6, 0, 120, 72 },
	{ -36, 324, -126, 420 }, { 36, 738, 90, 5994 }});
	Matrix matrix4_4_3 = Matrix(4, 4);

	EXPECT_EQ(matrix4_4_1 * 6, matrix4_4_2);
	EXPECT_EQ(matrix4_4_1 * 0, matrix4_4_3);
	EXPECT_EQ(matrix4_4_2 * 0, matrix4_4_3);

}

TEST_F(MATICE_TEST, MATRIX_CRAMER) {
	Matrix matrix2_2_1 = Matrix(2, 2);              //test 2 2 matrix by cramers rule
	matrix2_2_1.set(std::vector<std::vector< double > > { {1, 2}, { 3, 4 }});
	Matrix matrix2_2_2 = Matrix(2, 2);
	matrix2_2_2.set(std::vector<std::vector< double > > { {2, 2}, { 4, 4 }});

	EXPECT_TRUE((matrix2_2_1.solveEquation(std::vector<double> {2, 2})) == (std::vector<double> {-2, 2}));
	EXPECT_ANY_THROW(matrix2_2_1.solveEquation(std::vector<double> {1, 2, 3}));
	EXPECT_TRUE((matrix2_2_1.solveEquation(std::vector<double> {4, 4})) == (std::vector<double> {-4, 4}));
	EXPECT_ANY_THROW(matrix2_2_1.solveEquation(std::vector<double> {1}));

	Matrix matrix4_4_1 = Matrix(4, 4);              //test 4 4 matrix by cramers rule
	matrix4_4_1.set(std::vector<std::vector< double > > { {1, 2, 3, 4},
	{ 0, 1, 3, 4 },
	{ 0, 0, 1, 4 },
	{ 0, 0, 0, 1 }});

	EXPECT_TRUE((matrix4_4_1.solveEquation(std::vector<double> {1, 2, 3, 4})) == (std::vector<double> {-26, 25, -13, 4}));
	EXPECT_TRUE((matrix4_4_1.solveEquation(std::vector<double> {3, 3, 3, 3})) == (std::vector<double> {-18, 18, -9, 3}));
	EXPECT_ANY_THROW(matrix4_4_1.solveEquation(std::vector<double> {1, 2}));

	matrix = Matrix(2, 2);
	matrix.set(std::vector<std::vector< double > > { {1, 4}, { 2, 8 }});
	EXPECT_ANY_THROW(matrix.solveEquation(std::vector<double> {1, 2}));

}

TEST_F(MATICE_TEST, MATRIX_TRANSPOSE) {
	Matrix matrix2_3 = Matrix(2, 3);              //set up 2 3 matrix a transpose
	matrix2_3.set(std::vector<std::vector< double > > { {12, 1, 167}, { -2, 43.7, -20 }});
	Matrix matrix2_3_T = Matrix(3, 2);
	matrix2_3_T.set(std::vector<std::vector< double > > { {12, -2}, { 1, 43.7 }, { 167, -20 }});

	EXPECT_EQ(matrix2_3.transpose(), matrix2_3_T);
	EXPECT_EQ(matrix2_3_T.transpose(), matrix2_3);

	Matrix matrix4_4 = Matrix(4, 4);              //set up 4 4 matrix a transpose
	matrix4_4.set(std::vector<std::vector< double > > { {1, 2, 3, 4}, { 0.77, 2, 68, 1000 },
	{ 0, 99, 6, 3.2 }, { 4, 5, 6, 7 }});
	Matrix matrix4_4_T = Matrix(4, 4);
	matrix4_4_T.set(std::vector<std::vector< double > > { {1, 0.77, 0, 4}, { 2, 2, 99, 5 },
	{ 3, 68, 6, 6 }, { 4, 1000, 3.2, 7 }});

	EXPECT_EQ(matrix4_4.transpose(), matrix4_4_T);
	EXPECT_EQ(matrix4_4_T.transpose(), matrix4_4);

}

TEST_F(MATICE_TEST, MATRIX_INVERSE) {
	Matrix matrix2_2 = Matrix(2, 2);              //set up 2 2 matrix a inverse
	matrix2_2.set(std::vector<std::vector< double > > { {1, 2}, { 3, 4 }});
	Matrix matrix2_2_I = Matrix(2, 2);
	matrix2_2_I.set(std::vector<std::vector< double > > { {-2, 1}, { 1.5, -0.5 }});

	EXPECT_EQ(matrix2_2.inverse(), matrix2_2_I);

	Matrix matrix3_3 = Matrix(3, 3);              //set up 3 3 matrix a inverse
	matrix3_3.set(std::vector<std::vector< double > > { {3, -2, 4}, { 1, 0, 2 }, { 0, 1, 0 }});
	Matrix matrix3_3_I = Matrix(3, 3);
	matrix3_3_I.set(std::vector<std::vector< double > > { {1, -2, 2}, { 0, 0, 1 }, { -0.5, 1.5, -1 }});

	EXPECT_EQ(matrix3_3.inverse(), matrix3_3_I);

	Matrix matrix4_4 = Matrix(4, 4);              //set up 4 4 matrix a trying to inverse
	matrix4_4.set(std::vector<std::vector< double > > { {1, 2, 3, 4}, { 0.77, 2, 68, 1000 },
	{ 0, 99, 6, 3.2 }, { 4, 5, 6, 7 }});

	EXPECT_ANY_THROW(matrix4_4.inverse());

}

/*** Konec souboru white_box_tests.cpp ***/
