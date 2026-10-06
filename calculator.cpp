#include <iostream>
#include <string>
#include <vector>
#include <stack>

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

bool hasParenthesis(string expression){

  for(int i=0;i<expression.length();i++){

    if(expression[i]=='('||expression[i]==')'){

      return true;
    }
  }

  return false;
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

double CalculateExpression(string expression,bool& calculationSuccessful){

  vector<double> numbers = parseExpression(expression);
  vector<char> operators = parseOperator(expression);
  double result;
  
  if(numbers.size()!=0){
    
    result = numbers[0];

    for(int i=0;i<operators.size();i++){

      if(operators[i]=='*'||operators[i]=='/'){

        if(operators[i]=='*'){

          result = multiply(numbers[i],numbers[i+1]);
          numbers[i]=result;
          numbers.erase(numbers.begin()+i+1);
          operators.erase(operators.begin()+i);
          i--;
        }
        else{

          if(divide(numbers[i],numbers[i+1],numbers[i])){

            numbers.erase(numbers.begin()+i+1);
            operators.erase(operators.begin()+i);
            i--;
          }
          else{

            cerr << "Number can not be divided by zero";
            calculationSuccessful = false;
          }
        }
      }
    }

    result = numbers[0];

    for(int i=0;i<operators.size();i++){

      if(operators[i]=='+'){

        result = add(result,numbers[i+1]);
      }
      else if(operators[i]=='-'){

        result = subtract(result,numbers[i+1]);
      }
    }
  }
  else{

    cerr << "Invalid expression";
    calculationSuccessful = false;
  }

  return result;
}

void handleParanthesis(string& expression,bool& calculationSuccessful){

  int index1;
  int index2;
  
  while(hasParenthesis(expression)&&calculationSuccessful){

    stack<int> parenthesis;
    bool pairfound=false;
    
    for(int i=0;i<expression.length();i++){

      if(expression[i]=='('){

        parenthesis.push(i);
      }
      else if(expression[i]==')'){

        if(parenthesis.empty()){

          cerr << "Invalid parenthesis";
          calculationSuccessful=false;

          break;
        }
        else{
          index2=i;
          index1=parenthesis.top();
          parenthesis.pop();
          pairfound=true;

          break;
        }
      }
    }

    if(!pairfound){

      if(!parenthesis.empty()){

        cerr << "Invalid parenthesis";
        calculationSuccessful=false;

        break;
      }
    }

    if(calculationSuccessful&&pairfound){
      string inside=expression.substr(index1+1,index2-index1-1);
      
      if(!inside.empty()){
        
        double result = CalculateExpression(inside,calculationSuccessful);
  
        string final=to_string(result);
        expression.replace(index1,index2-index1+1,final);
      }
      else{

        cerr << "Invalid parenthesis";
        calculationSuccessful=false;
      }
    }
  }
}

int main(){

  int choice = menu();

  switch(choice){

    case 1:{

      string expression = getExpression();
      bool calculationSuccessful = true;
      double result;

      if(expression.length()!=0){

        if(hasParenthesis(expression)){

          handleParanthesis(expression,calculationSuccessful);
        
          if(calculationSuccessful){
          
            result=CalculateExpression(expression,calculationSuccessful);
          }
        }
        else{

          result=CalculateExpression(expression,calculationSuccessful);
        }

        if(calculationSuccessful){

          cout << result;
        }
        else{
        }

        break;
      }
      else{

        cerr << "Invalid expression";
        break;
      }
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
