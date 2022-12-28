#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;
class din_struct {
    int main()
    {
    	char* fileName = new char[50];
    	char* buf_name = new char[20];
    	char* buf_value = new char[10];
    
    	cout << "Enter name of file -> ";
    	cin >> fileName;
    	ifstream* inp = new ifstream(fileName);
    	if (!inp->good())
    	{
    		cout << "File opening error!\n";
    		system("PAUSE");
    		return 0;
    	}
    	while (!inp->eof())
    	{
    		inp->getline(buf_name, 20, ' ');
    		inp->getline(buf_value, 10, ' ');
    
    struct comp {
    	char name[20];
    	char value[10;
    	comp* next;
    };
    
    
    
    struct dyn_list {
    	comp* head;
    	comp* tail;
    };
    
    
    void constr_list(dyn_list& l)
    {
    	l.head = NULL;
    }
    
    
    bool chk_empty(dyn_list l)
    {
    	return (l.head == NULL);
    }
    
    dyn_list vars;
    constr_list(vars);
    
    
    
    void comp_in(dyn_list& l, char* n, char* v)
    {
    	comp* c = new comp();
    	
    	strcpy_s(c->name, 20, n);
    	strcpy_s(c->value, 10, v);
    	
    	c->next = NULL;
    	
    	if (chk_empty(l)) l.head = c;
    	else l.tail->next = c;
    	
    	l.tail = c;
    }
    
    
    comp* search(dyn_list l, char* n)
    {
    	while (l.head != NULL)
    	{
    		if (!strcmp(l.head->name, n))
    			return l.head;
    		l.head = l.head->next;
    	}
    	return l.head;
    }
    
    
    
    void comp_del(dyn_list& l, comp* c)
    {
    	if (c == l.head)
    	{
    		l.head = c->next;
    		return;
    	}
    	comp* r = new comp();
    	r = l.head;
    	while (r->next != c)
    		r = r->next;
    	r->next = c->next;
    	delete c;
    }
    
    
    void comp_edit(comp& c, char* v)
    {
    	strcpy_s(c.value, 10, v);
    }
    	}
    }
}

int main()
{
	char* fileName = new char[50];
	char* buf_name = new char[20];
	char* buf_value = new char[10];
	dyn_list vars;
	cout << "Enter name of file ";
	cin >> fileName;
	
	ifstream* inp = new ifstream(fileName);
	if (!inp->good())
	{
		cout << "File opening error\n";
		system("PAUSE");
		return 0;
	}
	
	constr_list(vars);
	
	while (!inp->eof())
	{
		inp->getline(buf_name, 20, ' ');
		inp->getline(buf_value, 10, ' ');
		comp_in(vars, buf_name, buf_value);
	}
	inp->close();
	
	comp* p = new comp();
	p = search(vars, "z");
	
	if (p) comp_del(vars, p);
	
	p = search(vars, "abc");
	
	if (p) comp_edit(*p, "2");
	
	ofstream* out = new ofstream(fileName);
	
	while (vars.head != NULL)
	{
		out->write(vars.head->name, strlen(vars.head->name));
		out->write(" ", 1);
		out->write(vars.head->value, strlen(vars.head->value));
		out->write(" ", 1);
		vars.head = vars.head->next;
	}
	
	out->close();
	
	system("PAUSE");
	return 0;
}
