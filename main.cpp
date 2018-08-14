//
//  main.cpp
//  排序算法
//
//  Created by 菜包 on 2018/8/7.
//  Copyright © 2018年 菜包. All rights reserved.
//




/** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 *
 *
 *                       警告(warning)
 *
 *                      必   读   手   册
 *
 *                       18/8/7 by 菜包
 *
 *
 *  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 *
 * 各种排序算法的集合。
 *
 *
 */





#include <iostream>

using namespace std;

#include <ctime>
#include <string.h>
#include <cstdlib>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <list>
#include <algorithm>

// N为数组大小
const int N = 10;

// 用于计算函数运算时间
clock_t Begin, End;
double duration;        // 记录运算时间


/**
 * 非线性时间比较类排序：
 * 通过比较来决定元素间的相对次序，由于其时间复杂度不能突破O(nlogn)，因此称为非线性时间比较类排序。
 */

/**交换排序**/
void bubbleSort1(int *, int);       // 冒泡排序
void bubbleSort2(int *, int);       // 冒泡排序优化
void cocktailSort(int *, int);      // 鸡尾酒排序
void oddEvenSort(int *, int);       // 奇偶排序
void gnomeSort1(int *, int);        // 侏儒排序
void gnomeSort2(int *, int);        // 侏儒排序优化
void combSort(int *, int);          // 梳排序

void quickSort1(int *, int);        // 快速排序
void quickSort2(int *, int);        // 快速排序优化


/**插入排序**/
void insertSort(int *, int);        // 直接插入排序

void shellSort(int *, int);         // 希尔排序


/**选择排序**/
void selectSort(int *, int);        // 选择排序
void heapSort(int *, int);          // 堆排序


/**归并排序**/
void mergeSort1(int *, int);        // 递归归并排序
void mergeSort2(int *, int);        // 非递归归并排序



/**
 * 线性时间非比较类排序：
 * 不通过比较来决定元素间的相对次序，它可以突破基于比较排序的时间下界
 * 以线性时间运行，因此称为线性时间非比较类排序。
 */
void countSort(int *, int);         // 计数排序
void pigeonholeSort(int *, int);    // 鸽巢排序
void bucketSort(int *, int);        // 桶排序
void radixSort1(int *, int);        // 基数排序

void BoGoSort(int *, int);          // BoGo排序

/******辅助函数*******/
void swap(int &, int &);            // 交换
bool arrayCompare(const int *, const int *, int);    // 数组比较
//bool compare(int, int);             // 整型比较

void allSortTimeCost();             // 所有排序消耗时间
void showMenu();


int main(int argc, const char *argv[]) {
    // insert code here...
    std::cout << "\t\tHello, World!\n";

    int a[N];
    bool judge;     //用于判断输入的选择是否合法
    int input;      //存储输入的选择

    // 函数指针，用于优化获取算法耗时
    void (*ptrFunction)(int *, int) = nullptr;

    // 随机函数，生成随机数组
    srand((unsigned) time(nullptr));
    for (int &i : a)
        i = rand() % (N * 10);

    cout << endl;
    cout << "\t\t" << "生成的随机数服从独立均匀分布" << endl;
    cout << "\t\t";
    cout << "排序前：" << endl;
    cout << "\t\t";

    for (int i : a)
        cout << i << ' ';

    cout << endl;

    showMenu();

    do {
        judge = false;
        cout << "             > 请做出你的选择：";
        cin >> input;
        switch (input) {
            case 10:
                ptrFunction = bubbleSort1;
                break;
            case 11:
                ptrFunction = bubbleSort2;
                break;
            case 12:
                ptrFunction = cocktailSort;
                break;
            case 13:
                ptrFunction = oddEvenSort;
                break;
            case 14:
                ptrFunction = gnomeSort1;
                break;
            case 15:
                ptrFunction = gnomeSort2;
                break;
            case 16:
                ptrFunction = combSort;
                break;
            case 20:
                ptrFunction = selectSort;
                break;
            case 30:
                ptrFunction = insertSort;
                break;
            case 40:
                ptrFunction = shellSort;
                break;
            case 50:
                ptrFunction = heapSort;
                break;
            case 60:
                ptrFunction = mergeSort1;
                break;
            case 61:
                ptrFunction = mergeSort2;
                break;
            case 70:
                ptrFunction = quickSort1;
                break;
            case 71:
                ptrFunction = quickSort2;
                break;
            case 80:
                ptrFunction = countSort;
                break;
            case 81:
                ptrFunction = bucketSort;
                break;
            case 82:
                ptrFunction = radixSort1;
                break;
            case 83:
                ptrFunction = pigeonholeSort;
                break;
            case 84:
                ptrFunction = BoGoSort;
                break;
            default:
                judge = true;
                cout << "\t\t输入错误，请重新选择" << endl;
        }
    } while (judge);

    // 排序并计算排序所耗时间
    Begin = clock();
    ptrFunction(a, N);
    End = clock();

    cout << endl;
    cout << endl;
    cout << "\t\t排序后：" << endl;
    cout << "\t\t";
    for (int i : a)
        cout << i << ' ';
    cout << endl;

    // 输出函数运算所消耗的时间
    duration = double(End - Begin) / CLOCKS_PER_SEC;
    cout << "\t\t用时" << setiosflags(ios::fixed) << duration << "秒" << endl;
    cout << endl;
    return 0;
}


void showMenu() {
    //    cout << "-----------------------------------------------" << endl;
    cout << "                                             " << endl;
    cout << "                                             " << endl;
    cout << "           *    请选择排序算法    *            " << endl;
    cout << "                                             " << endl;
    cout << "             10 <-   冒泡排序                 " << endl;
    cout << "             11 <-   冒泡排序优化              " << endl;
    cout << "             12 <-   鸡尾酒排序               " << endl;
    cout << "             13 <-   奇偶排序                 " << endl;
    cout << "             14 <-   侏儒排序                 " << endl;
    cout << "             15 <-   侏儒排序优化              " << endl;
    cout << "             16 <-   梳排序                   " << endl;
    cout << "             20 <-   选择排序                 " << endl;
    cout << "             30 <-   直接插入排序              " << endl;
    cout << "             40 <-   希尔排序                 " << endl;
    cout << "             50 <-   堆排序                   " << endl;
    cout << "             60 <-   归并排序 递归             " << endl;
    cout << "             61 <-   归并排序 非递归           " << endl;
    cout << "             70 <-   快速排序                 " << endl;
    cout << "             71 <-   快速排序优化              " << endl;
    cout << "             80 <-   计数排序                 " << endl;
    cout << "             81 <-   桶排序 目前只实现100以内的数" << endl;
    cout << "             82 <-   基数排序 数组实现         " << endl;
    cout << "             83 <-   鸽巢排序                 " << endl;
    cout << "             84 <-   BoGo排序                 " << endl;
    cout << "                                             " << endl;
    cout << "                                             " << endl;
    //    cout << "-----------------------------------------------" << endl;
}


/**
 * 所有排序时间消耗
 * 用于比较在时间上各算法的效率
 *
 * @param
 * @return
 */
void allSortTimeCost() {
    void (*ptrFunc)(int *, int) = nullptr;

}


/*****************交换排序*****************/
/**
 * 冒泡排序（稳定）
 *
 * 冒泡排序是一种简单的排序算法。
 * 它重复地走访过要排序的数列，一次比较两个元素，
 * 如果它们的顺序错误就把它们交换过来。走访数列的工作是重复地进行直到没有再需要交换，
 * 也就是说该数列已经排序完成。这个算法的名字由来是因为越小的元素会经由交换慢慢“浮”到数列的顶端。
 *
 * 算法描述: 1、比较相邻的元素。如果第一个比第二个大，就交换它们两个；
 *          2、对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对，这样在最后的元素应该会是最大的数；
 *          3、针对所有的元素重复以上的步骤，除了最后一个；
 *          4、重复步骤1~3，直到排序完成。
 */

/**
 * 交换函数
 *
 * 使用异或，整数异或本身为结果0，一个数异或0结果为本身。
 *
 * @param [in] a: 第一个元素
 * @param [in] a: 第二个元素
 * @return
 */
void swap(int &a, int &b) {
    a ^= b;
    b ^= a;        // 相当于b=a
    a ^= b;        // 相当于a=b
}


/**
 * 冒泡排序
 * @param [in] a: 数组名
 * @param [in] n: 数组大小
 * @return
 */
void bubbleSort1(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - i; j++) {
            if (a[j - 1] > a[j])        // 若顺序不适合则交换数据
                swap(a[j - 1], a[j]);       // 每一次遍历都有一个最大的数移动到最后，所以第二重遍历只需n-i次
        }
    }
}


/**
 * 冒泡排序优化
 *
 * 新增判断是否有交换元素，
 * 如果有交换元素，说明数组还未有序，
 * 如果没有交换过元素，说明数组已经有序。
 *
 * @param [in] a: 数组名
 * @param [in] n: 数组大小
 * @return
 */
void bubbleSort2(int a[], int n) {
    bool bSwap = true;
    while (bSwap) {     // bSwap为false则退出循环，排列顺序正确后即可提前结束
        bSwap = false;
        for (int i = 1; i < n; i++)
            if (a[i - 1] > a[i]) {
                swap(a[i - 1], a[i]);
                bSwap = true;       // 有数据交换则置bSwap为true
            }
        n--;
    }
}


/**
 * 鸡尾酒排序
 * 也称搅拌排序、快乐小时排序，
 * 鸡尾酒排序的元素比较和交换过程是双向的。
 *
 * @param [in] a: 数组名
 * @param [in] n: 数组大小
 * @return
 */
void cocktailSort(int a[], int n) {
    // 记录右侧最后一次交换的位置
    int lastRightExchangeIndex = 0;

    // 记录左侧最后一次交换的位置
    int lastLeftExchangeIndex = 0;

    // 无序数列的右边界，每次比较只需要比到这里为止
    int rightSortBorder = n - 1;

    // 无序数列的左边界，每次比较只需要比到这里为止
    int leftSortBorder = 0;

    for (int i = 0; i < n / 2; ++i) {
        // 有序标记，每一轮的初始时true
        bool isSorted = true;

        // 奇数轮，从左到右比较和交换
        for (int j = leftSortBorder; j < rightSortBorder; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);

                // 有元素交换，所以不是有序，标记变为false
                isSorted = false;
                lastRightExchangeIndex = j;
            }
        } // innerFor
        rightSortBorder = lastRightExchangeIndex;
        if (isSorted) {
            break;
        }

        // 偶数轮之前，重新标记为true
        isSorted = true;

        // 偶数轮，从右向左比较和交换
        for (int j = rightSortBorder; j > leftSortBorder; --j) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                // 有元素交换，所以不是有序，标记为false
                isSorted = false;
                lastLeftExchangeIndex = j;
            }
        } // innerFor
        leftSortBorder = lastLeftExchangeIndex;
        if (isSorted) {
            break;
        }
    } // outerFor
}



/**
 * 奇偶排序（稳定）
 *
 * 或砖排序
 * 奇偶排序实际上在多处理器环境中很有用，处理器可以分别同时处理每一个奇数对，
 * 然后又同时处理偶数对。因为奇数对是彼此独立的，每一刻都可以用不同的处理器比较和交换。这样可以非常快速地排序。
 *
 * 算法描述: 1、选取所有奇数列的元素与其右侧相邻的元素进行比较，将较小的元素排序在前面；
 *          2、选取所有偶数列的元素与其右侧相邻的元素进行比较，将较小的元素排序在前面；
 *          3、重复前面两步，直到所有序列有序为止。
 */

/**
 * 奇偶排序
 *
 * @param [in] a: 待排数组
 * @param [in] n: 数组大小
 * @return
 */
void oddEvenSort(int a[], int n) {
    bool flag = true;
    while (true) {
        flag = true;
        for (int i = 1; i < n - 1; i += 2) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                flag = false;
            }
        } // for

        for (int i = 0; i < n - 1; i += 2) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                flag = false;
            }
        } // for
        if (flag) {
            break;
        }
    } // while
}



/**
 * 侏儒排序（稳定）
 *
 * 或愚人排序（Stupid Sort）
 * 号称最简单的排序算法，只有一层循环，默认情况下前进冒泡，
 * 一旦遇到冒泡的情况发生就往回冒，直到把这个数字放好为止
 *
 * 算法描述: 1、邻元素之间两两进行比较，如果这两个元素逆序，则交换；
 *          2、如果遇到交换操作，变为向前冒泡，直至不发生交换操作位置。
 *          3、重复1、2步直到数组有序。
 */

/**
 * 侏儒排序
 *
 * @param [in] a: 待排数组
 * @param [in] n: 数组大小
 * @return
 */
void gnomeSort1(int a[], int n) {
    int i = 0;
    while (i < n) {
        if (i == 0 || a[i - 1] <= a[i]) {
            i++;
        } else {
            swap(a[i], a[i - 1]);
            i--;
        }
    }
}

//
///**
// * 整型元素比较
// *
// * @param [in] a: 第一个整型
// * @param [in] b: 第二个整型
// * @return [bo]
// */
//bool compare(int a, int b) {
//    return (a ^ 0 == b) != 0;
//}


/**
 * 侏儒排序优化
 *
 * 在回溯时记下当前位置，回溯后转跳到之前位置的下一个位置
 * 类似插入排序，不断把列表后面待排序的元素插入到列表前面已排序的部分中，
 * 但类似于冒泡排序那样比较并交换相邻元素。
 * 因此其算法复杂度与插入排序相当，但比插入排序需要更多的复制操作（用于交换相邻元素）。
 * 
 * @param [in] a: 待排数组
 * @param [in] n: 数组长度
 * @return
 */
void gnomeSort2(int a[], int n) {
    int i = 1;
    int previousPosition = -1;
    while (i < n) {
        if (i > 0 && a[i] < a[i - 1]) {
            // 记录侏儒回溯前的位置
            if (previousPosition == -1) {
                previousPosition = i;
            }

            swap(a[i], a[i - 1]);
            i--;
        } else {
            if (previousPosition == -1) {
                i++;
            } else {
                // 回溯后转跳到下一个位置
                i = previousPosition + 1;
                previousPosition = -1;
            }
        }
    } // while
}


/**
 * 梳排序（不稳定）
 *
 * 改良自泡沫排序和快速排序，其要旨在于消除乌龟，亦即在数组尾部的小数值，这些数值是造成冒泡排序缓慢的主因。
 * 相对地，兔子，亦即在数组前端的大数值，不影响冒泡排序的性能。
 *
 * 算法描述: 1、梳排序中，开始时的间距设置为数组长度，并在循环中以固定比率递减，通常递减率设置为1.3。
 *          2、在一次循环中，梳排序如同泡沫排序一样把数组从首到尾扫描一次，比较及交换两项，不同的是两项的间距不固定于1。
 *          3、如果间距递减至1，梳排序假定输入数组大致排序好，并以泡沫排序作最后检查及修正。
 *
 * 算法分析: 亦有人提议用1/\left(1-\frac{1}{e^\varphi}\right) \approx 1.247330950103979作递减率，
 *          同时增加换算表协助于每一循环开始时计算新间距。
 */
void combSort(int a[], int n) {
    double declineRate = 1.3;      // 递减率
    int gap = n;        // 间距
    bool isSwap = true;
    while (gap > 1 || isSwap) {
        // 若间距大于1或交换过，则间距递减
        if (gap > 1) {
            gap = (int) (gap / declineRate);
        }

        int i = 0;
        isSwap = false;
        while (i + gap < n) {
            if (a[i] > a[i + gap]) {
                swap(a[i], a[i + gap]);
                isSwap = true;
            }

            i++;
        } // innerWhile
    } // outerWhile
}


/**
 * 快速排序（不稳定）
 *
 * 通过一趟排序将待排记录分隔成独立的两部分，
 * 其中一部分记录的关键字均比另一部分的关键字小，
 * 则可分别对这两部分记录继续进行排序，以达到整个序列有序。
 *
 * 算法描述: 快速排序使用分治法来把一个串（list）分为两个子串（sub-lists）。
 *          1、从数列中挑出一个元素，称为 “基准”；
 *          2、重新排序数列，所有元素比基准值小的摆放在基准前面，
 *             所有元素比基准值大的摆在基准的后面（相同的数可以到任一边），
 *             在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；
 *          3、递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序。
 */

/**
 * quick_sort1函数：对s[l..r]进行排序
 *
 * @param [in] s: 待排序数组
 * @param [in] l: 起始位置
 * @param [in] n: 结束位置
 * @return
 */
void quick_sort1(int s[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;

        if (s[l] > s[r])
            swap(s[l], s[r]);
        if (s[m] > s[r])
            swap(s[m], s[r]);
        if (s[m] > s[l])
            swap(s[m], s[l]);

        int i = l, j = r, x = s[l];

        while (i < j) {
            while (i < j && s[j] >= x)      // 从右向左找第一个小于x的数
                j--;
            if (i < j)
                s[i++] = s[j];

            while (i < j && s[i] < x)       // 从左向右找第一个大于等于x的数
                i++;
            if (i < j)
                s[j--] = s[i];
        }

        s[i] = x;
        quick_sort1(s, l, i - 1);       // 递归调用
        quick_sort1(s, i + 1, r);
    }
}


/**
 * 快速排序优化
 * quick_sort2函数：对s[l..r]进行排序
 *
 * @param [in] s: 待排序数组
 * @param [in] l: 起始位置
 * @param [in] n: 结束位置
 * @return
 */
const int MAXSIZE = 7;

void quick_sort2(int s[], int l, int r) {
    if ((r - l) > MAXSIZE) {
        while (l < r) {
            int m = (l + r) / 2;
            if (s[l] > s[r])
                swap(s[l], s[r]);
            if (s[m] > s[r])
                swap(s[m], s[r]);
            if (s[m] > s[l])
                swap(s[m], s[l]);
            int i = l, j = r, x = s[l];
            while (i < j) {
                while (i < j && s[j] >= x)      // 从右向左找第一个小于x的数
                    j--;
                if (i < j)
                    s[i++] = s[j];

                while (i < j && s[i] < x)       // 从左向右找第一个大于等于x的数
                    i++;
                if (i < j)
                    s[j--] = s[i];
            }

            s[i] = x;
            quick_sort2(s, l, i - 1);       // 递归调用
            l = i + 1;
        }
    } else
        insertSort(s, r - l + 1);
}


/**
 * 快速排序
 *
 * @param [in] a: 待排序数组
 * @param [in] n: 数组大小
 * @return
 */
void quickSort1(int a[], int n) {
    quick_sort1(a, 0, n - 1);
}


/**
 * 快速排序优化
 *
 * @param [in] a: 待排序数组
 * @param [in] n: 数组大小
 * @return
 */
void quickSort2(int a[], int n) {
    quick_sort2(a, 0, n - 1);
}



/*****************插入排序*****************/
/**
 * 直接插入排序（稳定）
 *
 * 通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
 *
 * 算法描述: 一般来说，插入排序都采用in-place在数组上实现。
 *          1、从第一个元素开始，该元素可以认为已经被排序；
 *          2、取出下一个元素，在已经排序的元素序列中从后向前扫描；
 *          3、如果该元素（已排序）大于新元素，将该元素移到下一位置；
 *          4、重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
 *          5、将新元素插入到该位置后；
 *          6、重复步骤2~5。
 *
 * 算法分析: 插入排序在实现上，通常采用in-place排序（即只需用到O(1)的额外空间的排序），
 *          因而在从后向前扫描过程中，需要反复把已排序元素逐步向后挪位，为最新元素提供插入空间。
 */

/**
 * 直接插入排序
 *
 * @param [in] a: 数组名
 * @param [in] n: 数组大小
 * @return
 */
void insertSort(int a[], int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {      // a[i]<a[i-1]则需要将a[i]插入有序子表
            int temp = a[i];
            for (j = i - 1; j >= 0 && a[j] > temp; j--)     // 将比a[i]大的数据后移
                a[j + 1] = a[j];

            a[j + 1] = temp;        // 插入到正确的位置
        } // if
    } // outerFor
}



/**
 * 希尔排序（不稳定）
 *
 * 1959年Shell发明，第一个突破O(n2)的排序算法，是简单插入排序的改进版。
 * 它与插入排序的不同之处在于，它会优先比较距离较远的元素。
 * 希尔排序又叫缩小增量排序。
 *
 * 算法描述: 先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序。
 *          1、选择一个增量序列t1，t2，…，tk，其中ti>tj，tk=1；
 *          2、按增量序列个数k，对序列进行k 趟排序；
 *          3、每趟排序，根据对应的增量ti，将待排序列分割成若干长度为m的子序列，分别对各子表进行直接插入排序。
 *             仅增量因子为1 时，整个序列作为一个表来处理，表长度即为整个序列的长度。
 *
 * 算法分析: 希尔排序的核心在于间隔序列的设定。既可以提前设定好间隔序列，也可以动态的定义间隔序列。
 *          动态定义间隔序列的算法是《算法（第4版）》的合著者Robert Sedgewick提出的。
 */

/**
 * 希尔排序
 *
 * @param [in] a: 数组名
 * @param [in] n: 数组大小
 * @return
 */
void shellSort(int a[], int n) {
    int i, j;
    int increment = n;
    do {
        increment = increment / 3 + 1;      // 增量
        for (i = increment; i < n; i++) {       // 分组进行直接插入排序
            if (a[i] < a[i - increment]) {
                int temp = a[i];
                for (j = 1 - increment; j >= 0 && a[j] > temp; j -= increment)
                    a[j + increment] = a[j];
                a[j + increment] = temp;
            } // if
        } // outerFor
    } while (increment > 1);     // 直到增量为1结束
}



/*****************选择排序*****************/
/**
 * 选择排序（不稳定）
 *
 * 首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，
 * 再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
 * 以此类推，直到所有元素均排序完毕。
 *
 * 算法描述: n个记录的直接选择排序可经过n-1趟直接选择排序得到有序结果。
 *          1、初始状态：无序区为R[1..n]，有序区为空；
 *          2、第i趟排序(i=1,2,3…n-1)开始时，当前有序区和无序区分别为R[1..i-1]和R(i..n），
 *             该趟排序从当前无序区中-选出关键字最小的记录 R[k]，将它与无序区的第1个记录R交换，
 *             使R[1..i]和R[i+1..n)分别变为记录个数增加1个的新有序区和记录个数减少1个的新无序区；
 *          3、n-1趟结束，数组有序化了。
 *
 * 算法分析: 表现最稳定的排序算法之一，因为无论什么数据进去都是O(n2)的时间复杂度，
 *          所以用到它的时候，数据规模越小越好。唯一的好处可能就是不占用额外的内存空间了吧。
 *          理论上讲，选择排序可能也是平时排序一般人想到的最多的排序方法了吧。
 */

/**
 * 选择排序
 *
 * @param [in] a: 数组名
 * @param [in] n: 数组大小
 * @return
 */
void selectSort(int a[], int n) {
    int i, j, nMinIndex;
    for (i = 0; i < n; i++) {
        nMinIndex = i;      // 将当前索引定义为最小值索引
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[nMinIndex])        // 如果有小于当前最小值的数据
                nMinIndex = j;      // 将此索引赋值给 nMinIndex
        } // innerFor
        if (i != nMinIndex)
            swap(a[i], a[nMinIndex]);       // 若找到最小值则交换数据
    } // outerFor
}



/**
 * 堆排序（不稳定）
 *
 * 利用堆这种数据结构所设计的一种排序算法。
 * 堆积是一个近似完全二叉树的结构，并同时满足堆积的性质：即子结点的键值或索引总是小于（或者大于）它的父节点。
 *
 * 算法描述: 1、将初始待排序关键字序列(R1,R2….Rn)构建成大顶堆，此堆为初始的无序区；
 *          2、将堆顶元素R[1]与最后一个元素R[n]交换，此时得到新的无序区(R1,R2,……Rn-1)和新的有序区(Rn),且满足R[1,2…n-1]<=R[n]；
 *          3、由于交换后新的堆顶R[1]可能违反堆的性质，因此需要对当前无序区(R1,R2,……Rn-1)调整为新堆，
 *             然后再次将R[1]与无序区最后一个元素交换，得到新的无序区(R1,R2….Rn-2)和新的有序区(Rn-1,Rn)，
 *             不断重复此过程直到有序区的元素个数为n-1，则整个排序过程完成。
 */

/**
 * 将a[s..m]调整成为大顶堆
 *
 * @param [in] a: 数组名
 * @param [in] s: 待调整序列的起始位置
 * @param [in] n: 待调整序列的结束位置
 * @return
 */
void HeapAdjust(int a[], int s, int m) {
    int temp, j;
    temp = a[s];
    for (j = 2 * s + 1; j <= m; j = 2 * j + 1) {        // 从上到下，从左到右，将每个非叶结点及其子树调整为大顶堆
        if (j < m && a[j] < a[j + 1])
            j++;        // 用j标记左右子树中的较大值
        if (temp >= a[j])       // 若根节点大于左右子树，则跳出
            break;
        a[s] = a[j];        // 若根节点小于左右子树，则跟较大值交换
        s = j;
    }
    a[s] = temp;     // 交换数据
}


/**
 * 堆排序
 * 排序过程: 1、讲待排序的序列构建成一个大顶堆
 *          2、逐步将每个最大值的根结点与末尾元素交换，并且再调整其成为大顶堆
 *
 * @param [in] a: 数组名
 * @param [in] n: 数组大小
 * @return
 */
void heapSort(int a[], int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--) {      // 讲数组a构建成大顶堆
        HeapAdjust(a, i, n);

        for (i = n - 1; i > 0; i--) {
            swap(a[0], a[i]);       // 将堆顶数据与当前未排序子序列的最后一个数据交换
            HeapAdjust(a, 0, i - 1);     // 将a[0..i - 1]调整为大顶堆
        }
    }
}



/*****************归并排序*****************/
/**
 * 归并排序（稳定）
 *
 * 建立在归并操作上的一种有效的排序算法。
 * 该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。
 * 将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。
 * 若将两个有序表合并成一个有序表，称为2-路归并。
 *
 * 算法描述: 1、把长度为n的输入序列分成两个长度为n/2的子序列；
 *          2、对这两个子序列分别采用归并排序；
 *          3、将两个排序好的子序列合并成一个最终的排序序列。
 *
 * 算法分析: 归并排序是一种稳定的排序方法。和选择排序一样，归并排序的性能不受输入数据的影响，
 *          但表现比选择排序好的多，因为始终都是O(nlogn）的时间复杂度。代价是需要额外的内存空间。
 */

/**
 * Merge函数: 将有序的两个序列a[first..mid]和a[mid + 1..last]
 * 合并为一个有序序列temp[first..last]
 *
 * @param [in] a 待合并数组
 * @param [in] temp 临时数组存放归并结果
 * @param [in] first 起始位置
 * @param [in] mid 中间位置
 * @param [in] last 结束位置
 * @return
 */
void Merge(int a[], int temp[], int first, int mid, int last) {
    int i = first, j = mid + 1;
    int m = mid, n = last;
    int k = 0;

    while (i <= m && j <= n) {
        if (a[i] <= a[j])       // 依次比较两个序列的数，谁小取谁，将a中数据从小到大并入temp中
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= m)      // 将剩余的a[i..m]并入到temp中
        temp[k++] = a[i++];
    while (j <= n)      // 将剩余的a[j..n]并入到temp中
        temp[k++] = a[j++];
    for (int o = 0; o < k; o++)     // 最后将合并后数组temp复制给a
        a[first + o] = temp[o];
}


/**
 * mergesort函数: 将a[first..last]归并排序为temp[first..last]
 *
 * @param [in] a 待排序数组
 * @param [in] temp 临时数组存放排序结果
 * @param [in] first 起始位置
 * @param [in] last 结束位置
 * @return
 */
void mergesort(int a[], int temp[], int first, int last) {
    if (first < last) {
        int mid = (first + last) / 2;       // 分组
        mergesort(a, temp, first, mid);     // 递归将左边归并为有序
        mergesort(a, temp, mid + 1, last);      // 递归将右边归并为有序
        Merge(a, temp, first, mid, last);       // 合并有序序列
    } else {        // 递归结束条件：当分组后只有一个数据时，表示有序，递归结束
        temp[first] = a[first];
    }
}


/**
 * 递归归并排序
 *
 * @param [in] a: 待排序数组
 * @param [in] n: 数组大小
 * @return
 */
void mergeSort1(int a[], int n) {
    int *p = new int[n];       // 新建临时数组
    mergesort(a, p, 0, n - 1);
    delete[] p;
}


/**
 * mergeSort2函数：将a中相邻长度为s的子序列两两归并
 *
 * @param [in] a 待排序数组
 * @param [in] temp 临时数组存放归并结果
 * @param [in] s 子序列长度
 * @param [in] n 数组大小
 * @return
 */
void mergeSort2(int a[], int temp[], int s, int n) {
    int i = 0;
    while (i <= n - 2 * s) {
        Merge(a, temp, i, i + s - 1, i + 2 * s - 1);        // 两两归并
        i = i + 2 * s;
    }
    if (i < n - s)      // 归并剩下的最后两个序列（数组可能不会正好被平分）
        Merge(a, temp, i, i + s - 1, n - 1);
}


/**
 * 非递归归并排序
 *
 * @param [in] a: 待排序数组
 * @param [in] n: 数组大小
 * @return
 */
void mergeSort2(int a[], int n) {
    int *p = new int[n];       // 新建临时数组
    int k = 1;
    while (k < n) {
        mergeSort2(a, p, k, n);     // 将a中相邻长度为k的子序列两两归并
        k = 2 * k;      // 子序列长度加倍
    }
    delete[] p;
}



/**
 * 计数排序（稳定）
 *
 * 计数排序不是基于比较的排序算法，其核心在于将输入的数据值转化为键存储在额外开辟的数组空间中。
 * 作为一种线性时间复杂度的排序，计数排序要求输入的数据必须是有确定范围的整数。
 *
 * 算法描述: 1、找出待排序的数组中最大和最小的元素；
 *          2、统计数组中每个值为i的元素出现的次数，存入数组C的第i项；
 *          3、对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）
 *          4、反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1。
 *
 * 算法分析: 计数排序是一个稳定的排序算法。
 *          当输入的元素是n个0到k之间的整数时，时间复杂度是O(n+k)，空间复杂度也是O(n+k)
 *          其排序速度快于任何比较排序算法
 *          当k不是很大并且序列比较集中时，计数排序是一个很有效的排序算法
 */

/**
 * 获取数组中的最大元素
 *
 * @param [in] a: 待排序数组
 * @param [in] n: 数组大小
 * @return [in]: 数组中的最大元素
 */
int getArrayMaxElem(const int a[], int n) {
    int maxElem = 0;
    for (int i = 0; i < n; ++i) {
        if (maxElem < a[i])
            maxElem = a[i];
    }
    return maxElem;
}


/**
 * 获取数组中的最小元素
 *
 * @param [in] a: 数组
 * @param [in] n: 数组大小
 * @return [in]: 数组中的最小元素
 */
int getArrayMinElem(const int a[], int n) {
    int minElem = 0;
    for (int i = 0; i < n; ++i) {
        if (minElem > a[i])
            minElem = a[i];
    }
    return minElem;
}


/**
 * 计数排序
 *
 * @param [in] a: 待排序数组
 * @param [in] n: 数组大小
 * @return
 */
void countSort(int a[], int n) {
    int sortIndex = 0;
    int maxElem = getArrayMaxElem(a, n);
    int *bucket = new int[maxElem + 1]{0};
    int bucketLen = maxElem + 1;

    for (int i = 0; i < n; ++i) {
        bucket[a[i]]++;
    } // for

    for (int j = 0; j < bucketLen; ++j) {
        while (bucket[j] > 0) {
            a[sortIndex++] = j;
            bucket[j]--;
        } // while
    } // for
}


/**
 * 鸽巢排序
 *
 * 鸽巢排序的执行速度快于任何一种排序，但其却需要很大的辅助空间，而且其适用于很少的数值范围内的排序。
 * 当待排序数组中出现很多不相等的元素时，鸽巢排序的效率会降低。
 * 鸽巢排序的辅助数组的大小取决与待排序数组的数值范围，辅助空间的大小为待排序数组中的最大值与最小值之差加1。
 *
 * 算法描述: 计数排序优化版本
 *          1、给定一个待排序数组，创建一个备用数组（鸽巢），并初始化元素为0，备用数组的索引即是待排序数组的值。
 *          2、扫描待排序数组时，将待排序序列中的每一个数减去最小值当作辅助数组中的下标自增1。
 *          3、扫描辅助数组，若辅助数组中有非零的数据，则该位置的下标加上最小值就是待排序数组中原来的数据。
 *
 * 算法分析: 我们一般很少使用鸽巢排序，因为它很少可以在灵活性，简便性，尤是速度上超过其他排序算法。
 *          事实上，桶排序较鸽巢排序更加的实用。
 */

/**
 * 鸽巢排序
 *
 * @param [in] a: 待排序数组
 * @param [in] n: 数组大小
 * @return
 */
void pigeonholeSort(int a[], int n) {
    int maxElem = getArrayMaxElem(a, n);
    int minElem = getArrayMinElem(a, n);
    int *pigeonhole = new int[maxElem - minElem + 1]{0};        // 鸽巢大小为最大值与最小值之差加1

    for (int i = 0; i < n; ++i) {
        pigeonhole[a[i] - minElem]++;
    }

    for (int i = 0, j = 0; i < maxElem - minElem + 1; ++i) {
        while (pigeonhole[i] > 0) {
            a[j++] = i + minElem;
            pigeonhole[i]--;
        } // while
    } // for
}

/**
 * 桶排序（稳定）
 *
 * 桶排序是计数排序的升级版。它利用了函数的映射关系，高效与否的关键就在于这个映射函数的确定。
 * 主要适用于小范围整数数据，且独立均匀分布，可以计算的数据量很大，而且符合线性期望时间。
 * 桶排序 (Bucket sort)的工作的原理：假设输入数据服从均匀分布，
 * 将数据分到有限数量的桶里，每个桶再分别排序（有可能再使用别的排序算法或是以递归方式继续使用桶排序进行排）。
 *
 * 算法描述:
 *          1、设置一个定量的数组当作空桶；
 *          2、遍历输入数据，并且把数据一个一个放到对应的桶里去；
 *          3、对每个不是空的桶进行排序；
 *          4、从不是空的桶里把排好序的数据拼接起来。
 *
 * 算法分析: 桶排序最好情况下使用线性时间O(n)，桶排序的时间复杂度，
 *          取决与对各个桶之间数据进行排序的时间复杂度，因为其它部分的时间复杂度都为O(n)。
 *          很显然，桶划分的越小，各个桶之间的数据越少，排序所用的时间也会越少。但相应的空间消耗就会增大。
 */

struct Node {
    int value = 0;
    Node *next = nullptr;
};


/**
 * 获取桶的数量，这里并不是线性的
 *
 * @param [in] n: 数组大小
 * @return [in]: 桶的个数
 */
int getBucketCount(int n) {
    if (n <= 100)
        return 10;
    else if (n <= 1000)
        return 50;
    else if (n <= 10000)
        return 100;
    else
        return 1000;
}



/** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 *
 *
 *                       警告(warning)
 *               该算法现在只能计算十个100以内的正整数
 *                      18/8/7 by 菜包
 *
 *
 *  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 */
/**
 * 桶排序
 *
 * @param [in] a: 待排数组
 * @param [in] n: 数组大小
 * @return
 */
void bucketSort(int a[], int n) {
    int length = getBucketCount(n);     // 桶的数量是固定的，并不是线性分布，可以优化
    Node key[N];       // 指针数组，每一个数作为节点插入到这个数组中
    int number = 0;        // 映射函数值（桶的大小）
    Node *p = nullptr, *q = nullptr;       // 插入节点时的临时指针
    int counter = 0;
    for (int i = 0; i < length; ++i) {
        // 初始化
        key[i].value = 0;
        key[i].next = nullptr;
    }

    for (int i = 0; i < n; ++i) {
        Node *insert = new Node();     // 临时节点
        insert->value = a[i];
        insert->next = nullptr;

        number = a[i] / length;     // 映射函数，这里可以优化

        // 若数组为空，则直接插入；若不为空，则先比较大小再插入
        // 此处在插入的过程中排序
        // 另一种算法方式为先插入，待所有数据插入完毕后再用其他排序算法对每一条非空链表排序
        if (key[number].next == nullptr) {
            key[number].next = insert;
        } else {
            p = &key[number];
            q = key[number].next;
            while ((q != nullptr) && (q->value <= a[i])) {
                q = q->next;
                p = p->next;
            } // while
            insert->next = q;
            p->next = insert;
        } // if
    } // for

    for (int i = 0; i < length; ++i) {
        // 把排好序的数组复制到目标数组（原数组）
        p = key[i].next;
        if (p == nullptr)
            continue;
        while (p != nullptr) {
            a[counter++] = p->value;
            p = p->next;
        } // while
    } // for
}



/**
 * 基数排序（稳定）
 *
 * 基数排序是按照低位先排序，然后收集；再按照高位排序，然后再收集；依次类推，直到最高位。
 * 有时候有些属性是有优先级顺序的，先按低优先级排序，再按高优先级排序。
 * 最后的次序就是高优先级高的在前，高优先级相同的低优先级高的在前。
 *
 * 算法描述:
 *          1、取得数组中的最大数，并取得位数；
 *          2、arr为原始数组，从最低位开始取每个位组成radix数组；
 *          3、对radix进行计数排序（利用计数排序适用于小范围数的特点）。
 *
 * 算法分析: 基数排序基于分别排序，分别收集，所以是稳定的。
 *          但基数排序的性能比桶排序要略差，每一次关键字的桶分配都需要O(n)的时间复杂度，
 *          而且分配之后得到新的关键字序列又需要O(n)的时间复杂度。
 *          假如待排数据可以分为d个关键字，则基数排序的时间复杂度将是O(d*2n) ，当然d要远远小于n，因此基本上还是线性级别的。
 *          基数排序的空间复杂度为O(n+k)，其中k为桶的数量。一般来说n>>k，因此额外空间需要大概n个左右。
 */

/**
 * 求最大位数
 *
 * @param [in] a: 数组
 * @param [in] n: 数组长度
 * @return [in] d: 数组中元素的最大位数
 */
int getMaxDigit(int a[], int n) {
    int maxElem = getArrayMaxElem(a, n);

    int d = 1;
    int p = 10;
    while (maxElem >= p) {
        maxElem /= 10;
        ++d;
    }
    return d;
}


/**
 * 基数排序 数组实现
 */
void radixSort1(int a[], int n) {
    int length = getMaxDigit(a, n);
    int *tmp = new int[n];
    int *count = new int[10];
    int i, j, k;
    int radix = 1;
    for (i = 1; i <= length; ++i) {     // 遍历每位
        for (j = 0; j < 10; ++j) {
            // 每次分配前清空计数器
            count[j] = 0;
        }

        for (j = 0; j < n; ++j) {
            // 统计每个桶中的记录数
            k = (a[j] / radix) % 10;
            count[k]++;
        }

        for (j = 1; j < 10; ++j) {
            // 将tmp中的位置依次分配给每个桶
            count[j] = count[j - 1] + count[j];
        }

        for (j = n - 1; j >= 0; --j) {
            // 将所有桶中记录依次收集到tmp中
            k = (a[j] / radix) % 10;
            tmp[count[k] - 1] = a[j];
            count[k]--;
        } // innerFor

        for (j = 0; j < n; ++j) {
            // 将临时数组的内容复制到a中
            a[j] = tmp[j];
        }

        radix = radix * 10;
    } // outerFor

    delete[]tmp;
    delete[]count;
}


/**
 * BoGo排序
 *
 * 坑不人不偿命的排序，时间复杂度高达〇(n*n!)
 *
 * 算法描述: 1、把队列随机打乱
 *          2、队列有序？OK；否则重新执行第1步
 *
 * 算法分析: 如果我理解没有错，这个算法能排序好的概率是不是跟中彩票一样
 */

/**
 * 比较函数
 *
 * @param [in] arr1: 第一个数组
 * @param [in] arr2: 第二个数组
 * @param [in] n: 数组大小
 * @return [bo]: 相等返回true，不等返回false
 */
bool arrayCompare(const int arr1[], const int arr2[], int n) {
    for (int i = 0; i < n; ++i) {
        if (arr1[i] != arr2[i])
            return false;
    }
    return true;
}


/**
 * BoGo排序
 *
 * @param [in] a 待排序数组
 * @param [in] n 数组大小
 * @return
 */
void BoGoSort(int a[], int n) {
    // 初始化数组b并把a赋值给b
    int *b = new int[N]{0};
    for (int i = 0; i < n; ++i) {
        b[i] = a[i];
    }

    // 让数组b有序，以便判断数组a是否有序
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - i; j++) {
            if (b[j - 1] > b[j])
                swap(b[j - 1], b[j]);
        }
    }

    int count = 0;      // 计数器
    srand((unsigned) time(nullptr));
    int index1, index2;
    while (!arrayCompare(a, b, n)) {     // 若两数组不相等，继续循环
        for (int i = 0; i < 10; ++i) {
            // 获取两个随机索引
            index1 = rand() % n;
            index2 = rand() % n;
            if (index1 == index2)
                continue;
            // 交换数组元素实现打乱数组
            swap(a[index1], a[index2]);
        } // for
        count++;
        if (count % 1000000 == 0)
            cout << "已经比较了" << count << "次..." << endl;
    } // while
    cout << "最终运算了" << count << "次..." << endl;

}
