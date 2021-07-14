#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int>* m_pIsRunning = nullptr;
    m_pIsRunning = new vector<int>();
    for (int i = 0; i < 10; i++)
        m_pIsRunning->push_back(i);
    vector<int>::iterator iter = m_pIsRunning->begin();
    for (; iter != m_pIsRunning->end(); iter++) {
        cout << *iter << endl;
        m_pIsRunning->erase(iter);
    }
    return 0; 
}