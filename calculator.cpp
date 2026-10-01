#include <iostream>
#include <string>
#include <vector>

using namespace std;

int menu(){

  int choice;
  cout << "Welcome to the Calculator" << '\n';
  cout << "1. Arithmetic Operations" << endl;
  cout << "0. Exit" << '\n';
  cout << "Enter your Choice: ";
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

vector<char> parseOperator(string expression){

  string current;
  vector<char> operators;

  for(int i=0;i<expression.length();i++){

    if(expression[i]=='+'||expression[i]=='-'||expression[i]=='*'||expression[i]=='/'){

      operators.push_back(expression[i]);

    }
  }

  return operators;
}

double add(double a,double b){

  double sum;
  sum=a+b;

  return sum;
}

double subtract(double a,double b){

  double subtract;
  subtract=a-b;

  return subtract;
}

double multiply(double a,double b){

  double multiplication;
  multiplication=a*b;

  return multiplication;
}

bool divide(double a,double b,double& result){

  if(b==0){

    return false;

  }
  else{

    result=a/b;

    return true;

  }
}

int main(){

  int choice = menu();

  switch(choice){

    case 1:{

      string expression = getExpression();
      vector<double> numbers = parseExpression(expression);
      vector<char> operators = parseOperator(expression);
      double result = numbers[0];
      bool calculationSuccessful=true;
      
      for(int i=0;i<operators.size();i++){

        if(operators[i]=='+'){
      
          result=add(result,numbers[i+1]);

        }
        else if(operators[i]=='-'){

          result=subtract(result,numbers[i+1]);

        }
        else if(operators[i]=='*'){

          result=multiply(result,numbers[i+1]);

        }
        else if(operators[i]=='/'){

          if(divide(result,numbers[i+1],result)){

          }
          else{

            cerr << "Number can not be divided by zero";
            calculationSuccessful=false;
            break;

          }
        }
      }

      if(calculationSuccessful){

        cout << result;

      }
      else{

      }

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
