#pragma once
#include <string>
#include <vector>
#include "Example.h"
#include "TreeNode.h"
#include "Dataset.h"

using namespace std;

class DecisionTree
{
public:
	DecisionTree(Dataset trainset);	// ����ѵ�����ݼ������ڳ�ʼ������������ʼ�������л�ѵ���õ�һ�þ�����
	
	TreeNode* root;	// ����ѵ���õ��ľ�����

	// �����ĸ��������ڼ�����Ϣ����
	double entropy(double p1, double p2);
	double entropy_binary(double p);
	double entropy_remain(string attribute, vector<Example> examples);
	double info_gain(string attribute, vector<Example> examples);
	// ������Ϣ����ѡ��attribute
	string importance(vector<string> attributes, vector<Example> examples);
	// ��ӦFigure 18.5��������α���룺DECISION-TREE-LEARNING
	TreeNode* learn(vector<Example> examples, vector<string> attributes, vector<Example> parent_examples);
	// ����������������Ԥ��
	int classify_rec(Example& example, TreeNode* root);
	vector<int> classify(vector<vector<string>> test_raw_values);
private:
	TreeNode* plurality_value(vector<Example> examples);	// ����examples�еĶ�����ǩȡֵ�����ص�TreeNodeΪ��������Ҷ�ڵ㣬��Ӧα�����е�PLURALITY-VALUE(parent examples)����
	vector<Example> get_examples(vector<Example> examples, string attr, string option);	// ��ȡexamples�У�attrֵΪoption����
	int get_positive_count(vector<Example>& examples);	// ��ȡexamples������������
	bool have_same_class(vector<Example> examples);	// �ж�examples�ı�ǩ�Ƿ���ͬ
	vector<string> remove_attribute(vector<string> attributes, string attribute); // ��attributes�б����Ƴ�attribute
};

