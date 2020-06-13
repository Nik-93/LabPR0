  
# include  < mpi.h >
# include  < iostream >
# include  < cstdlib >
использование  пространства имен  std ;
int  main ( int argc, char ** argv)
{
MPI_Init (& argc, & argv); int rank, size;
MPI_Comm_rank (MPI_COMM_WORLD, & rank);
MPI_Comm_size (MPI_COMM_WORLD, & size);
cout << " Hello MPI " << endl << " Rank - " << rank << " , размер
- « << размер << endl;
MPI_Finalize ();
вернуть  0 ;
}
