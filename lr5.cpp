# include  < stdio.h >
# include  < omp.h >
int  main ( int argc, char * argv [])
{
int n;
# pragma omp parallel private (n)
 {
n = omp_get_thread_num ();
# pragma omp section
 {
# pragma omp section
 {
 printf ( " 1 секция, процесс% d \ n " , n);
 }
# pragma omp section
 {
 printf ( " 2 секция, процесс% d \ n " , n);
 }
# pragma omp section
 {
 printf ( " 3 секция, процесс% d \ n " , n);
 }
 }
 printf ( " Параллельная дилянка, процесс% d \ n " , n);
 }
}
