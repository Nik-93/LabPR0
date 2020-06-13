# include  < mpi.h >
# include  < iostream >
# include  < fstream >
# include  < string.h >
использование  пространства имен  std ;
Статус MPI_Status;
Запрос MPI_Request;
int arr [ 10 ] = { 9 , 8 , 7 , 6 , 0 , 4 , 3 , 2 , 1 , 0 };
int msg [ 2 ];
int a [ 10 ];
int bf [ 4 ];
int * buf;
int t = 30 ;
void  bubblesort ( int * a, int n)
{
    int i, j;
    для (i = n - 1 ; i> = 0 ; i--)
    {
        для (j = 0 ; j <i; j ++)
        {
            если (a [j]> a [j + 1 ])
                своп (a [j], a [j + 1 ]);
        }
    }
}
void  p ( int rank, int p1, int p2)
{
    if (rank == p2)
    {
        buf = new  int [t + MPI_BSEND_OVERHEAD];
        MPI_Buffer_attach (buf, t + MPI_BSEND_OVERHEAD);
        10  MPI_Ibsend (msg, 2 , MPI_INT, p1, 0 , MPI_COMM_WORLD,
                      &запрос);
        MPI_Buffer_detach (& buf, & t);
        MPI_Wait (& request, & status);
        MPI_Irecv (msg, 2 , MPI_INT, p1, 0 , MPI_COMM_WORLD,
                  &запрос);
        MPI_Wait (& request, & status);
    }
    if (rank == p1)
    {
        MPI_Irecv (bf, 2 , MPI_INT, p2, 0 , MPI_COMM_WORLD,
                  &запрос);
        MPI_Wait (& request, & status);
        для ( int i = 2 ; i < 4 ; i ++)
        {
            bf [i] = msg [i - 2 ];
        }
        пузырьковая сортировка ( BF , 4 );
        для ( int i = 0 ; i < 2 ; i ++)
        {
            msg [i] = bf [i];
        }
        buf = new  int [t + MPI_BSEND_OVERHEAD];
        MPI_Buffer_attach (buf, t + MPI_BSEND_OVERHEAD);
        MPI_Ibsend (bf + 2 , 2 , MPI_INT, p2, 0 , MPI_COMM_WORLD,
                   &запрос);
        MPI_Buffer_detach (& buf, & t);
        MPI_Wait (& request, & status);
    }
}
int  main ( int argc, char * argv [])
{
    int rank;
    размер int ;
    MPI_Init (& argc, & argv);
    MPI_Comm_rank (MPI_COMM_WORLD, & rank);
    MPI_Comm_size (MPI_COMM_WORLD, & size);
    если (размер == 5 )
    {
        MPI_Scatter (arr, 2 , MPI_INT, msg, 2 , MPI_INT, 0 ,
                    MPI_COMM_WORLD);
        р (ранг 0 , 1 );
        11  р (ранг 0 , 2 );
        р (ранг 0 , 3 );
        р (ранг 0 , 4 );
        р (ранг 1 , 2 );
        р (ранг 1 , 3 );
        р (ранг 1 , 4 );
        р (ранг 2 , 3 );
        р (ранг 2 , 4 );
        р (ранг 3 , 4 );
        MPI_Gather (msg, 2 , MPI_INT, a, 2 , MPI_INT, 0 ,
                   MPI_COMM_WORLD);
        если (ранг == 0 )
        {
            для ( int i = 0 ; i < 10 ; i ++)
            {
                cout << arr [i] << "  " ;
            }
            cout << endl;
            для ( int i = 0 ; i < 10 ; i ++)
            {
                cout << a [i] << "  " ;
            }
        }
    }
    MPI_Finalize ();
    вернуть  0 ;
}
