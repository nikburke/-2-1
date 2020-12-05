#include <iostream>
#include <chrono>
using namespace std;

int main() {
setlocale(LC_ALL, "Russian");
int temp;
const int n = 100;

short A[n];

    for (int i = 0; i < n; ++i){

      A[i] = rand() % 201 - 99;

        
    }
cin.sync();
auto start1 = chrono::high_resolution_clock::now();
int min=100;
int max=-100;
for(int i=0; i<n; i++){
  if (A[i] > max)
  max = A[i];
  if (A[i] < min)
  min = A[i];

}
auto end1 = chrono::high_resolution_clock::now();
chrono::duration<float> duration1 = end1-start1;

auto start2 = chrono::high_resolution_clock::now();
    int counter=0;
	for(int i=1;i<n;i++){
		for(int j=i; j>0 && A[j-1]>A[j];j--){
			counter++;
			int tmp=A[j-1];
			A[j-1]=A[j];
			A[j]=tmp;
		}
	}

  auto end2 = chrono::high_resolution_clock::now();
  chrono::duration<float> duration2 = end2-start2;
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

auto start3 = chrono::high_resolution_clock::now();
min=100;
max=-100;
for(int i=0; i<n; i++){
  if (A[i] > max)
  max = A[i];
  if (A[i] < min)
  min = A[i];

}
auto end3 = chrono::high_resolution_clock::now();
chrono::duration<float> duration3 = end3-start3;
    
    cout<< '\n'<< "время затраченое на сортировку массива " <<duration2.count();

    cout << '\n' <<  "минимальный  элемент массива" << min;
    cout << '\n' << "максимальный элемент массива" << max;
    cout<< '\n'<< "время затраченое на поиск минимального и максимальног элемента масива до сортировки " <<duration1.count();

    cout<< '\n'<< "время затраченое на поиск минимального и максимальног элемента масива после сортировки " <<duration1.count();
    
    int sred =(max+min)/2;
    cout << '\n' << "среднее значение минимального и максимального " << sred << " индексы с этим значением ";


int zero = 0;
for(int i=0; i<n; i++){
  if (A[i] == sred){
    cout << i;
    zero= zero+1;
}
}

if (zero==0)
  cout << "отсутствуют";
    cout << '\n'  << '\n' << "Введите целое число: ";
    int a;
    cin >> a;
    int chisla = 0;
  
  for(int i=0; i<n; i++){
  if (A[i] < a)
    chisla = chisla+1;
}

cout  << "чисел в массиве меньше вашего " << chisla;

   cout << '\n' << "Введите целое число: ";
    int b;
    cin >> a;
    chisla = 0;
  
  for(int i=0; i<n; i++){
  if (A[i] > b)
    chisla = chisla+1;
}

cout << "чисел в массиве больше вашего " << chisla;

auto start4 = chrono::high_resolution_clock::now();
   cout << '\n' << "Введите первый индекс: ";
    cin >> a;
    cout << "Введите второй индекс: ";
    cin >> b;
    short bufer;

   bufer = A[a];
  A[a] = A[b];
  A[b]= bufer;
auto end4 = chrono::high_resolution_clock::now();
chrono::duration<float> duration4 = end4-start4;
    
    cout<< '\n'<< "время затраченое на обмен значениями " <<duration4.count();

    return 0;
}



