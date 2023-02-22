#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>


int top_pop(std::stack<int> aStack){
    int value = aStack.top();
    aStack.pop();
    return value;
}
void exo1_pile_ou_face(){
    std::string input = "";
    std::vector<std::string> inputs;
    std::stack<int> compute;
    while (input!="!"){
        std::cout << "Entrez un nombre ou une operation : ";
        std::cin >> input;
        std::cout << input << std::endl;
        if (input != "!"){
            inputs.push_back(input);
        }
    }
    if (inputs.size() < 3){
        std::cout << "Pas assez d'éléments";
    }
    else{
        for (int index = 0; index < inputs.size(); index++){
            if (inputs[index] == "*"){
                int nb1 = compute.top();
                compute.pop();
                int nb2 = compute.top();
                compute.pop();
                compute.push(nb1*nb2);
            }
            else if (inputs[index] == "-"){
                int nb2 = compute.top();
                compute.pop();
                int nb1 = compute.top();
                compute.pop();
                compute.push(nb1-nb2);
            }
            else if (inputs[index] == "+"){
                int nb1 = compute.top();
                compute.pop();
                int nb2 = compute.top();
                compute.pop();
                compute.push(nb1+nb2);
            }
            else if (inputs[index] == "/"){
                int nb1 = compute.top();
                compute.pop();
                int nb2 = compute.top();
                compute.pop();
                compute.push(nb1/nb2);
            }
            else {
                compute.push(std::stoi(inputs[index], nullptr));
            }
        }
    }
    std::cout << compute.top() << std::endl;


}

void exo2_200_metres(){
    std::vector<double> times = {26.1, 25.6, 25.7, 25.2, 24.7, 25.0};
    std::map<std::string, double> container;
    std::sort(times.begin(), times.end());

    container["minimun"] = times.front();
    container["maximun"] = times.back();
    container["moyenne"] = times.front()+times.back()/times.size();


    if (times.size()%2 == 0){
        container["medianne"] = (times[(times.size()/2)-1]+times[(times.size()/2)])/2;
    }
    else{
        container["medianne"] = times[times.size()/2];
    }

    std::cout << container["medianne"] << std::endl;
    std::cout << times[times.size()/2] << "   " << times[(times.size()/2)+1] << std::endl;
}

int main()
{
    // exo1_pile_ou_face();
    exo2_200_metres();
    return 0;
}
