# включить «tbb / parallel_sort.h»
# include  < math.h >
используя  пространство имен  tbb ;
const  int N = 100000 ;
плавать [N];
плавать b [N];
void  SortExample ()
{
для ( int i = 0 ; i <N; i ++)
{
a [i] = sin (( double ) i);
b [i] = cos (( double ) i);
}
параллельный_сорт (a, a + N);
параллельная_сортировка (b, b + N, std :: большее < float > ());
} 
