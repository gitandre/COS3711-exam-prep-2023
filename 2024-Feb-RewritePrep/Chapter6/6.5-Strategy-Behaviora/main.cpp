#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <vector>

// Strategy Interface
class SortingStrategy {
public:
    virtual void sort(std::vector<int> &arr) const = 0;
};

// ConcreteStrategyA: Bubble Sort
class BubbleSortStrategy : public SortingStrategy {
public:
    void sort(std::vector<int> &arr) const override {

        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};

// Helper function for QuickSortStrategy
int partition(std::vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Recursive quick sort function
void quickSort(std::vector<int> &arr, int low, int high) {

    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ConcreteStrategyB: Quick Sort
class QuickSortStrategy : public SortingStrategy {
public:
    void sort(std::vector<int> &arr) const override {
        if (!arr.empty()) {
            quickSort(arr, 0, arr.size() - 1);
        }
    }
};

// Context
class SortedList {
private:
    SortingStrategy *strategy;
    std::vector<int> arr;

public:
    SortedList() : strategy(nullptr) {}

    ~SortedList() {
        delete strategy;
    }

    void setStrategy(SortingStrategy *s) {
        delete strategy; // Clean up existing strategy
        strategy = s;
    }

    void add(int element) {
        arr.push_back(element);
    }

    void sort() {
        // Dynamically choose the sorting strategy based on the array's size
        if (arr.size() > 10) {
            std::cout << "Using QuickSort strategy" << std::endl;
            setStrategy(new QuickSortStrategy());

        } else {
            std::cout << "Using BubbleSort strategy" << std::endl;
            setStrategy(new BubbleSortStrategy());

        }

        if (strategy) {
            strategy->sort(arr);
        }
    }

    void print() {
        for (int element: arr) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
};


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // List 1 with 12 items - should use QuickSortStrategy
    SortedList list;
    // Add elements
    for (int i: {5, 2, 9, 1, 5, 3, 8, 4, 7, 6, 11, 10}) {
        list.add(i);
    }

    list.sort(); // Will choose QuickSortStrategy due to the size being greater than 10
    list.print(); // Output the sorted array

    // List 1 with 8 - should use BubbleSortStrategy
    SortedList list2;
    // Add elements
    for (int i: {5, 3, 8, 4, 7, 6, 11, 10}) {
        list2.add(i);
    }

    list2.sort(); // Will choose QuickSortStrategy due to the size being greater than 10
    list2.print(); // Output the sorted array

    return QCoreApplication::exec();
}
