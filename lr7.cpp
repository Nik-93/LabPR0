# include  < cilk / cilk.h >
# include  < cilk / reducer_opadd.h > cilk :: reducer_opadd < int > sum;
void  addum ()
{
сумма + = 1 ;
}
int  main ()
{
сумма + = 1 ;
cilk_spawn addum ();
сумма + = 1 ;
cilk_sync;
возврат суммы get_value ();
} 
