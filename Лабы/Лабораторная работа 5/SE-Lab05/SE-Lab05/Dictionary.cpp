#include "Dictionary.h"
#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace Dictionary;
using namespace std;

Instance Dictionary::Create(const char* name, int maxsize)
{
	
	if (strlen(name) > ENTRYNAMEMAXSIZE)
	{
		throw THROW01; 
	}
	if (DICTMAXSIZE < maxsize)
	{
		throw THROW02; 
	}
	Instance NewDict;
	strcpy_s(NewDict.name, name);
	NewDict.maxsize = maxsize; 
	NewDict.dictionary = new Entry[maxsize];
	return NewDict;
}
void Dictionary::addEntry(Instance& inst, Entry ed)
{
	int size = inst.size;
	if (size >= inst.maxsize)
	{
		throw THROW03;   
	}
	for (int i = 0; i < size; i++)
	{
		if (inst.dictionary[i].id == ed.id) throw THROW04;
	}
	inst.dictionary[size] = ed;
	inst.size++;
}
void Dictionary::DelEntry(Instance& inst, int id)
{
	bool isFound = false;
	for (int i = 0; i < inst.size; i++)
	{
		if (inst.dictionary[i].id == id)
		{
			isFound = true;
			for (int j = i; j < inst.size; j++)
			{
				inst.dictionary[j] = inst.dictionary[j + 1];
			}
			inst.size--;
			break;
		}
	}
	if (!isFound) throw THROW06; 
}
Entry Dictionary::GetEntry(Instance& inst, int id)
{
	bool isFound = false;
	for (int i = 0; i < inst.size; i++)
	{
		if (inst.dictionary[i].id == id)
		{
			
			return inst.dictionary[i];
		}
	}
	if (!isFound) throw THROW05; 
}
void Dictionary::UpdEntry(Instance& inst, int id, Entry new_ed)
{
	bool isFound = false;
	for (int i = 0; i < inst.size; i++)
	{
		if (inst.dictionary[i].id == id)
		{
			for (int j = i; j < inst.size; j++)
			{
				if (new_ed.id == inst.dictionary[j].id) throw THROW08; //"UpdEntry: дублирование идентификатора"
			}
			isFound = true;

			inst.dictionary[i].id = new_ed.id;
			strcpy_s(inst.dictionary[i].name, new_ed.name);
			break;
		}
		else if (new_ed.id == inst.dictionary[i].id) throw THROW08; //"UpdEntry: дублирование идентификатора"
	}
	if (!isFound)
	{
		throw THROW07; 
	}
}
void Dictionary::Print(Instance& d)
{

	cout << endl << "--------" << d.name << "--------" << endl;
	for (int i = 0; i < d.size; i++)
	{
		cout << "ID = " << d.dictionary[i].id
			<<' ' << d.dictionary[i].name << endl;
	}
}
void Dictionary::Delete(Instance& inst)
{
	delete[] inst.dictionary;
}