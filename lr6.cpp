# include  < stdio.h >
# include  < omp.h >
int  main ( int argc, char * argv [])
{
блокировка omp_lock_t ; int n;
 omp_init_lock (& lock);
# pragma omp parallel private (n)
 {
n = omp_get_thread_num ();
 while (! omp_test_lock (& lock))
 { 
printf ( " Секция закрита, потик% d \ n " , n);

 }
 printf ( « Початок закрытой чеки, потик% d \ n » , н);

 printf ( " Kinec 'zakritoj cekcii, potik% d \ n " , n);
 omp_unset_lock (& lock);
 }
 omp_destroy_lock (& lock);
}
