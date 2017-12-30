#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <cstddef>
#include <string>

#define TYPE float
#define TYPE_SIZE 16
#define ATOT atof
#define SEP (",")


class FileNotFound {};
class FileReadError {};
class NoMemory {};
class InvalidRow {};
class InvalidCol {};
class InvalidRead {};
class InvalidDimensions {};

struct MatrixInfo {
	bool isUpper;
	bool isLower;
	bool isZero;
	bool isIdentity;

	MatrixInfo() : isUpper{false}, isLower{false}, isZero{false}, isIdentity{false} {}
};

class Matrix {

	std::size_t num_rows;
	std::size_t num_cols;

	TYPE **data;

	void determineInfo();


public:
	MatrixInfo *info;
	Matrix(const char *file_name);
	Matrix(std::size_t nrows = 0, std::size_t ncols = 0);
	Matrix(const Matrix &other); // Copy Constructor
	Matrix(Matrix &&other); // Move Constructor
	Matrix &operator=(Matrix other); // Copy Assigment
	~Matrix();


	void allocateData();
	void print() const;

	void readCSV(const char *file_name);

	bool operator==(const Matrix& rhs) const;
	bool operator!=(const Matrix &rhs) const;

	std::size_t getCols() const { return this->num_cols; }
	std::size_t getRows() const { return this->num_rows; }



    Matrix operator*(const Matrix &rhs) const;
	Matrix operator+(const Matrix &rhs) const;
	Matrix operator-(const Matrix &rhs) const;

	Matrix operator*(TYPE scalar) const;
	Matrix operator+(TYPE scalar) const;
	Matrix operator-(TYPE scalar) const;

	// bool isUpperTriangular();
	// bool isLowerTriangular();
	// bool isZero();
	// bool isIdentity();

	friend void swap(Matrix &first, Matrix &second);

	// Matrix &operator=(Matrix &&other); // Move Assignment (No need since copy/swap)
	// Matrix naiveMultiply(const Matrix &rhs) const;
	// Matrix naiveLoopMultiply(const Matrix &rhs) const;

    // TYPE dot(const Matrix &lhs, const Matrix &rhs, std::size_t row, std::size_t col) const;
	// Matrix operator+ (const Matrix& c) const;

	// void WriteTo(std::string file);
	// int my_atoi(const char *str);

	// void readCSV(std::istream &input);

};
// Don't declare static functions in header unless inlining the function
// static size_t csvRowCount(const char *file_name); 
// static size_t csvColumnCount(const char *file_name);



#endif
