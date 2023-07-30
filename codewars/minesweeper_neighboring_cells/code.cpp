#include <assert.h>
#include <iostream>

void print_board(char **board, const int rows, const int cols)
{
    std::string line_sep(cols * 2 + 1, '-');
    for(int i(0); i < rows; i++)
    {
        std::cout << line_sep << std::endl << '|';
        for(int j(0); j < cols; j++)
        {
            std::cout << board[i][j] << '|';
        }
        std::cout << std::endl;
    }
    std::cout << line_sep << std::endl;
}

void compute_number_mines(char **board, const int rows, const int cols)
{
    for(int i(0); i < rows; i++)
    {
        for(int j(0); j < cols; j++)
        {
            if(board[i][j] == 'R')
            {
                int cnt(0);
                for(int p((i - 1 >= 0)? i - 1 : i); p < (i + 1 < rows? i + 2 : i + 1); p++)
                {
                    for(int q((j - 1 >= 0)? j - 1 : j); q < (j + 1 < cols? j + 2 : j + 1); q++)
                    {
                        if(board[p][q] == 'o')
                        {
                            cnt++;
                        }
                    }
                }
                board[i][j] = cnt + '0';
            }
        }
    }
}

void assertMatricesEquals( char **mat1, char **mat2, const int rows, const int cols)
{
  int areEqual = 1;                                                
  for (int i = 0; i < rows && areEqual; i++)
  {
    for (int j = 0; j < cols && areEqual; j++)
      if ((mat1)[i][j] != (mat2)[i][j])                           
        areEqual = 0;                                              
  }                                                              
  assert(areEqual == 1);
}

void basic_test()
{
    char **array;
    array = new char *[5];
    for(int i = 0; i <5; i++)
      array[i] = new char[5]; 

    // static init & copy to dynamic matrix
    char mat1[5][5] = {{' ',' ','o','o',' '},
                       {' ','o',' ','D',' '},
                       {' ','D','R',' ',' '},
                       {' ',' ','o','o',' '},
                       {' ',' ',' ',' ','o'}};
            
    // static init & copy to dynamic matrix
    char output[5][5]={{' ',' ','o','o',' '},
                       {' ','o',' ','D',' '},
                       {' ','D','3',' ',' '},
                       {' ',' ','o','o',' '},
                       {' ',' ',' ',' ','o'}};        
    
    char **array_gt;
    array_gt = new char *[5];
    for(int i = 0; i <5; i++)
      array_gt[i] = new char[5]; 
    
    for(int i=0;i<5;i++)
      for(int j=0;j<5;j++)
      {
        array[i][j] = mat1[i][j];
        array_gt[i][j] = output[i][j];
      }
      
    compute_number_mines(array,5,5);
    
    assertMatricesEquals(array,array_gt,5,5);
    
    for(int i = 0; i <5; i++)
      delete array[i];
    delete [] array;
    
    for(int i = 0; i <5; i++)
      delete array_gt[i];
    delete [] array_gt;

}

void basic_test2()
{
    char **array;
    array = new char *[5];
    for(int i = 0; i <5; i++)
      array[i] = new char[5]; 

    // static init & copy to dynamic matrix
    char mat1[5][5] = {{'o',' ','o','o',' '},
                       {'R','o','R','D','o'},
                       {'o','D','R',' ',' '},
                       {' ','o','o','o',' '},
                       {' ',' ',' ',' ','o'}};
            
    // static init & copy to dynamic matrix
    char output[5][5]={{'o',' ','o','o',' '},
                       {'3','o','3','D','o'},
                       {'o','D','4',' ',' '},
                       {' ','o','o','o',' '},
                       {' ',' ',' ',' ','o'}};        
    
    char **array_gt;
    array_gt = new char *[5];
    for(int i = 0; i <5; i++)
      array_gt[i] = new char[5]; 
    
    for(int i=0;i<5;i++)
      for(int j=0;j<5;j++)
      {
        array[i][j] = mat1[i][j];
        array_gt[i][j] = output[i][j];
      }
      
    compute_number_mines(array,5,5);
    
    assertMatricesEquals(array,array_gt,5,5);
    
    for(int i = 0; i <5; i++)
      delete array[i];
    delete [] array;
    
    for(int i = 0; i <5; i++)
      delete array_gt[i];
    delete [] array_gt;
}

int main()
{
    basic_test();
    basic_test2();
}