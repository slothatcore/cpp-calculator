#include <iostream>
#include <string>
#include <vector>
using namespace std;

int menu(){

  int choice;
  cout << "Welcome to the Calculator" << '\n';
  cout << "1. Arithmetic Operations" << endl;
  cout << "0. Exit" << '\n';
  cout << "Enter your Choice";
  cin >> choice;
  return choice;

}

string getExpression(){

  string expression;
  cout << "Enter the expression: ";
  cin.ignore();
  getline(cin,expression);
  return expression;

}

vector<double> parseExpression(string expression){

  expression+=' ';
  string current;
  double currentnumber;
  vector<double> numbers;

  for(int i=0;i<expression.length();i++){

    if(expression[i]!=' '&&expression[i]!='+'&&expression[i]!='-'&&expression[i]!='*'&&expression[i]!='/'){

      current+=expression[i];

    }
    else{

      if(current.length()!=0){

        currentnumber=stod(current);
        numbers.push_back(currentnumber);
        current="";

      }
    }
  }

  return numbers;

}

double add(vector<double> numbers){

  double sum;
  sum=numbers[0];

  for(int i=1;i<numbers.size();i++){

    sum+=numbers[i];

  }

  return sum;
}

int main(){

  int choice = menu();

  switch(choice){

    case 1:{

      string expression = getExpression();
      vector<double> numbers = parseExpression(expression);
      double sum = add(numbers);

      cout << sum;

      break;
    }
    case 0:{

      break;

    }
    default:{

      cout << "Invalid Choice";

    }
  }

  return 0;

}
