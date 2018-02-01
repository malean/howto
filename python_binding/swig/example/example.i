 %module example
 %{
 /* Put header files here or function declarations like below */
 extern double My_variable;
 extern int fact(int n);
 extern int my_mod(int x, int y);
 extern char *get_time();

 struct Foo
 {
   int num;
   double val;
 };



 %}
 
 struct Foo
 {
   int num;
   double val;
 };
 extern double My_variable;
 extern int fact(int n);
 extern int my_mod(int x, int y);
 extern char *get_time();
