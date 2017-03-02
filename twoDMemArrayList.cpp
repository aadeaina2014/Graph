

////////////////////////////////////////////////////
/*
 Usage of Vectors
 PreAllocation Vector, Matrix
 Iterators for Vectors
 Iterators for Matrixs
 Resizing of vectors ( in constructorrs and overload constructorss;






                                                */
///////////////////////////////////////////////////
#include  <iostream>
#include <vector>
using namespace std;

int main(void)
{
	// Matrix Vector Pre-Allocation 
	vector<int> feature_vector(8);
	vector < vector <int> >  matrixyz(8);
	vector < vector <int> >  matrixx(8, vector<int>(8));
	vector < vector <int> >  matrix(8, vector<int>(8));
	vector < vector <int> >::iterator matrixRowIterator;

	int x = 5;
	int * xptr = &x;
	cout << "content of variable" << *xptr<< endl;
	cout << "content of variable" << x << endl;


	int** myArray;
	int** myArray2;

	///////////////////////////////////////////
	// Allocate Memory For Arrays 2D Arrays/
	///////////////////////////////////////////
	int size = 4;
	
	
	
	// Alloction
	myArray = new int*[size];

	for (int i = 0; i < size; ++i)
	{
		myArray[i] = new int[size];	//allocate memomry for every row
	}



	// initialization
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			myArray[i][j] = 0;
		}
	}
	cout << "Content of last location:" << myArray[3][3] << endl;


	// Deallocation
	for (int i = 0; i < arrayMaxRow; ++i)
	{

		delete[] myArray[i]; //cleanup x
	}
	delete[] myArray; //cleanup y


	

	feature_vector[0] = 1;
	cout << "feature vector size:"<< feature_vector.size() << endl;
	cout << "feature vector postion 7:" << feature_vector[7] << endl;
	feature_vector.push_back (2);
	cout << "feature vector size:" << feature_vector.size() << endl;
	cout << "feature vector postion 8:" << feature_vector[8] << endl;

	matrixRowIterator = matrix.begin();
	 *matrixRowIterator = feature_vector; // write Data to first element of matrix

	cout << "Matrix size : "<< matrix.size() << endl;
	cout << "Matrix first Element: " << matrix[0][0] << endl;
	cout << "Matrix last Element: " << matrix[7][7] << endl;
	



	feature_vector.resize(20, 0);

	matrix.resize(10, vector<int>(10));
	cout << "Content of feature vector postion 20 is " << feature_vector[19] << endl;
	//matrix[9][9] = 0;
	cout << "content of Matrix last Element: " << matrix[9][9] << endl;
	system("pause");
	return EXIT_SUCCESS;
}