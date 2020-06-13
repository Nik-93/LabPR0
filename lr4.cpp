# включить  " mpi.h "
# include  < stdio.h >
int  main ( int argc, char * argv [])
{
 int counter, message, myid, numprocs, server;
 int color, remote_leader_rank, i, ICTAG = 0 ;
 Статус MPI_Status;
 MPI_Comm oldcommdup, splitcomm, oldcomm, inter_comm;
 MPI_Init (& argc, & argv);
 oldcomm = MPI_COMM_WORLD;
 MPI_Comm_dup (oldcomm, & oldcommdup);
 MPI_Comm_size (oldcommdup, & numprocs);
 MPI_Comm_rank (oldcommdup, & myid);
сервер = numprocs- 1 ;
 color = (myid == сервер);
 MPI_Comm_split (oldcomm, color, myid и splitcomm);
 if (! color) {
 remote_leader_rank = сервер;
 }
 еще {
remote_leader_rank = 0 ;
 }
 MPI_Intercomm_create (splitcomm, 0 , oldcommdup,
remote_leader_rank, ICTAG, & inter_comm);
 MPI_Comm_free (& oldcommdup);
 if (myid == сервер) {
 for (i = 0 ; i <сервер; i ++) {
 MPI_Recv (& message, 1 , MPI_INT, i, MPI_ANY_TAG,
inter_comm, & status);
 printf ( « Обработать ранг% i, полученный% i от% i \ n » ,
myid, сообщение, статус. MPI_SOURCE );
 }
 }
 еще {
 counter = myid;
 MPI_Send (& counter, 1 , MPI_INT, 0 , 0 , inter_comm);
 printf ( « Обрабатывать ранг% i, отправляю% i \ n » , myid, counter);
 }
 MPI_Comm_free (& inter_comm);
 MPI_Finalize ();
}
