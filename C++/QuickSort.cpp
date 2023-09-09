#include <iostream>
using namespace std;

struct Student {
    int roll;
    string name;
    float sgpa;
};

void show1(Student* a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i]->roll << " ";
        cout << a[i]->name << " ";
        cout << a[i]->sgpa << "\n";
    }
}

void show2(Student* a[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        cout << n-i << ". Roll no: " << a[i] -> roll;
        cout << ", Name: " << a[i]->name;
        cout << ", SGPA: " << a[i]->sgpa << "\n\n";
    }
}

int partition(Student* a[], int l, int u) {
    Student* t;
    float p = a[l]->sgpa;
    int start = l, end = u;

    while (a[start]->sgpa <= p && start < u) {
        start++;
    }

    while (a[end]->sgpa > p) {
        end--;
    }

    if (start < end) {
        swap(a[start], a[end]);
    } else {
        t = a[end];
        a[end] = a[l];
        a[l] = t;
    }
    return end;
}

void quickSort(Student* a[], int l, int u) {
    if (l < u) {
        int loc = partition(a, l, u);
        quickSort(a, l, loc - 1);
        quickSort(a, loc + 1, u);
    }
}

int main() {
    int i = 0, n, ch;
    float m;
    Student* s[5];

    cout << "1.Insert Records: ";
    cout << "\n2.First 10 toppers of the class: \n";
    cout << "Enter your choice: ";
    cin >> n;
    if (n == 1) {
        cout << "Enter details: \n";
        do {
            cout << "\nStudent " << i + 1 << " Records: \n";
            s[i] = new Student();
            cout << "Roll no: ";
            cin >> s[i]->roll;
            cout << "Name: ";
            cin >> s[i]->name;
            cout << "SGPA: ";
            cin >> s[i]->sgpa;
            cout << "Do you want to input more records? (Enter 1 if yes)\n";
            cin >> ch;
            i++;
        } while (ch == 1);
    }

    cout << "First 10 toppers: \n";
    quickSort(s, 0, i - 1);
    show2(s, i);
    
    // Free allocated memory
    for (int j = 0; j < i; j++) {
        delete s[j];
    }

    return 0;
}
