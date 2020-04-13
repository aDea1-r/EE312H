#ifndef _MazeParams_h
#define _MazeParams_h 1

#include <string.h>
#include <stdio.h>

extern int MAZE_SIZE;
#define MATRIX_SIZE (2*MAZE_SIZE+1)

class Maze
{
public:

    Maze(void) :
        _rows(0),
        _cols(0),
        _buffer(nullptr)
    {
    }

    ~Maze(void)
    {
        delete[] this->_buffer;
    }



    Maze &operator=(const Maze &o)
    {
        delete[] this->_buffer;
        this->_Copy(o);
        return *this;
    }

    int *operator[](int row)
    {
        return this->_buffer + (row * this->_cols);
    }

    bool operator==(const Maze &o)
    {
        if (this->_rows != o._rows || this->_cols != o._cols)
        {
            return false;
        }

//        return memcmp(this->_buffer, o._buffer, this->_rows * this->_cols * sizeof(int)) == 0;
          for(int i=0;i<this->_cols * this->_cols;i++){
              if(this->_buffer[i] != o._buffer[i]){
                  return false;
              }
          }
          return true;
    }

    void print() {
        for (int i = 0; i < this->_rows; i++) {
            for (int j = 0; j < this->_cols; j++) {
                printf("%d  ", _buffer[i]);
            }
            printf("\n");
        }
    }

    operator int *(void)
    {
        return this->_buffer;
    }

    void Reset()
    {
        this->_rows = MATRIX_SIZE;
        this->_cols = MATRIX_SIZE;

        delete[] this->_buffer;
        this->_buffer = new int[this->_rows * this->_cols];
        const int my_random_number=0x12345678;
        for(int i=0;i<this->_rows * this->_cols;i++){
            this->_buffer[i] = my_random_number;
        }
    }

private:

    void _Copy(const Maze &o)
    {
        this->_rows = o._rows;
        this->_cols = o._cols;

        this->_buffer = new int[this->_rows * this->_cols];
        memcpy(this->_buffer, o._buffer, this->_rows * this->_cols * sizeof(int));
    }

    int _rows;
    int _cols;

    int *_buffer;
};

extern Maze maze;
extern Maze maze_soln;

#endif /* _MazeParams_h */
