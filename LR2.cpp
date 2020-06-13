# include  < mpi.h >
# include  < iostream >
использование  пространства имен  std ;
int  main ( int argc, char * argv [])
{
 int * buffer;
 int myrank;
 Статус MPI_Status;
 int buffsize = 1 ;
 int TAG = 0 ;
 MPI_Init (& argc, & argv);
 MPI_Comm_rank (MPI_COMM_WORLD, & myrank);
 если (myrank == 0 )
 {
buffer = ( int *) malloc (buffsize + MPI_BSEND_OVERHEAD);
 MPI_Buffer_attach (буфер, размер буфера + MPI_BSEND_OVERHEAD);
буфер = ( int *) 10 ;
 MPI_Bsend (& buffer, buffsize, MPI_INT, 1 , TAG, MPI_COMM_WORLD);
 MPI_Buffer_detach (& buffer, & buffsize);
 }
еще
{
 MPI_Recv (& buffer, buffsize, MPI_INT, 0 , TAG, MPI_COMM_WORLD, & status);
cout << " полученный: " << буфер << endl;

}
MPI_Finalize ();
система ( « ПАУЗА » );
вернуть  0 ;
}
