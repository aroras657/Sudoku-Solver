#include<fstream>
#include<cstdlib>
#include<iostream>
using namespace std;
struct Puzzle{
int data[9][9];
} puzzle =
{
{
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
}
};
void display(Puzzle &puzzle);
void solver(Puzzle &puzzle);
void execute();
int check(const Puzzle &puzzle);
int findSolution(Puzzle &puzzle);
void builtin();
void newf();
void display(Puzzle &puzzle){
for (int i = 0; i < 9; ++i)
{
cout << " ";
for (int j = 0; j < 9; ++j)
{ if(puzzle.data[i][j]==0)
cout << " "<<" | ";
else
cout << puzzle.data[i][j] << " | ";
}
cout << endl;
cout << " ------------------------------------";
cout << endl;
}
}
void solver(Puzzle &puzzle){
if (findSolution(puzzle))
{
display(puzzle);
}
else
std::cout << "No solution\n";
}
void execute(){
char x;
cout << "\nThe puzzle is:\n\n";
display(puzzle);
cout << endl;
cout << "press a key to get the solution\n";
cin >> x;
system("cls");
cout << "The solution is:\n";
solver(puzzle);
}
int check(const Puzzle &puzzle){
for (int i = 0; i < 9; ++i)
for (int j = 0; j < 9; ++j)
for (int k = j + 1; k < 9; ++k)
{
if (puzzle.data[i][j] != 0 && puzzle.data[i][j] ==
puzzle.data[i][k])
return 0;
if (puzzle.data[j][i] != 0 && puzzle.data[j][i] ==
puzzle.data[k][i])
return 0;
if (puzzle.data[j % 3 + (i % 3) * 3][j / 3 + (i / 3) * 3] != 0
&&
puzzle.data[j % 3 + (i % 3) * 3][j / 3 + (i / 3) * 3] ==
puzzle.data[k % 3 + (i % 3) * 3][k / 3 + (i / 3) * 3])
return 0;
}
return 1;
}
int findSolution(Puzzle &puzzle){
int x = -1;
int y = -1;
int min = 10;
for (int i = 0; i < 9; ++i)
for (int j = 0; j < 9; ++j)
{
if (puzzle.data[i][j] == 0)
{
int c = 0;
for (int k = 1; k <= 9; ++k)
{
puzzle.data[i][j] = k;
if (check(puzzle))
++c;
puzzle.data[i][j] = 0;
}
if (min > c)
{
min = c;
x = i;
y = j;
}
}
}
if (x == -1)
return 1;
for (int k = 1; k <= 9; ++k)
{
puzzle.data[x][y] = k;
if (check(puzzle))
if (findSolution(puzzle))
return 1;
}
puzzle.data[x][y] = 0;
return 0;
}
void builtin(){
int h;int a;
ifstream file;
cout << "Select a puzzle\n";
cout << "Puzzle 1\n";
cout << "Puzzle 2\n";
cout << "Puzzle 3\n";
cin >> h;
switch(h)
{
case 1:file.open("1.txt");break;
case 2:file.open("2.txt");break;
case 3:file.open("3.txt");break;
default:cout << "Wrong input";
}
file >> a;
while(file)
{
for(int i=0;i<9;i++)
for(int j=0;j<9;j++)
{
puzzle.data[i][j] = a;
file>>a;
}
}
execute();
}
void newf(){
cout << "Please enter the elements row wise\n";
cout << "Please enter 0 for blank space\n";
for(int i=0;i<9;i++)
{
long long int a;
cout << "Enter row " << i + 1 << ":";
cin >> a;
for(int j=8;j>=0;j--)
{
int b = a%10;
a = a/10;
puzzle.data[i][j] =b;}
}
execute();
cout << endl;
}

int main(){
int a;
cout << "Welcome to Sudoku Solver\n\n";
do
{
cout << "You may choose from one of the following\n\n";
cout << "1.Try me out on an in built sudoku puzzzle\n";
cout << "2.Enter a new sudoku puzzle for me to solve\n";
cout <<"3.Exit\n";
cin >> a;
switch(a){
case 1:builtin();break;
case 2:newf();break;
case 3: break;
}
}while(a!=3);
}