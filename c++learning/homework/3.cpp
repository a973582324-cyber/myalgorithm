#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <iomanip>
#include <map>

using namespace std;

// 哈夫曼树节点结构
struct HuffmanNode {
    double weight;
    char id; // 标志字母，内部节点用 '#'
    HuffmanNode *left, *right;

    HuffmanNode(char id, double weight) : id(id), weight(weight), left(nullptr), right(nullptr) {}
};

// 优先队列的比较对象（最小堆）
struct Compare {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return l->weight > r->weight;
    }
};

// 递归遍历树以生成编码
void getCodes(HuffmanNode* root, const string& str, map<char, string>& huffmanCode) {
    if (!root) return;

    // 叶子节点
    if (root->id != '#') {
        huffmanCode[root->id] = str;
    }

    getCodes(root->left, str + "0", huffmanCode);
    getCodes(root->right, str + "1", huffmanCode);
}

void buildHuffmanTree(const vector<pair<char, double>>& frequencies) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> minHeap;

    // 创建叶子节点并加入最小堆
    for (const auto& pair : frequencies) {
        minHeap.push(new HuffmanNode(pair.first, pair.second));
    }

    // 循环合并直到堆中只有一个根节点
    while (minHeap.size() != 1) {
        HuffmanNode *left = minHeap.top(); minHeap.pop();
        HuffmanNode *right = minHeap.top(); minHeap.pop();

        // 内部节点的频率为两子节点之和
        HuffmanNode *top = new HuffmanNode('#', left->weight + right->weight);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    // 生成编码
    map<char, string> huffmanCode;
    getCodes(minHeap.top(), "", huffmanCode);

    // 格式化输出结果
    cout << "====================================\n";
    cout << " 字母 |  出现频率  |  哈夫曼编码 \n";
    cout << "------------------------------------\n";
    double wpl = 0;
    for (const auto& pair : frequencies) {
        string code = huffmanCode[pair.first];
        cout << "  " << pair.first << "   |    " 
             << fixed << setprecision(2) << pair.second 
             << "    |  " << code << "\n";
        wpl += pair.second * code.length();
    }
    cout << "====================================\n";
    cout << "平均码长 (WPL) = " << fixed << setprecision(2) << wpl << "\n";
}

int main() {
    // 录入题目中的字母和频率
    vector<pair<char, double>> frequencies = {
        {'A', 0.02}, {'B', 0.03}, {'C', 0.06}, {'D', 0.07},
        {'E', 0.10}, {'F', 0.19}, {'G', 0.21}, {'H', 0.32}
    };

    buildHuffmanTree(frequencies);

    return 0;
}