#pragma once
#include <iostream>
//���ﶨ���ˡ��������ҡ�ʧ�ܡ���ȥ��������Ϊ
enum class Action
{
	LEFT,
	UP,
	RIGHT,
	DOWN,
	FAILURE,
	CUTOFF
};

extern std::ostream& operator<<(std::ostream& os, Action action);