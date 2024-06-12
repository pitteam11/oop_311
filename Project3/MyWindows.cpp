#include <iostream>

using namespace std;

#define MAX_WIDTH 1024
#define MAX_HEIGHT 768

class Rectangle {
protected:
	int x;
	int y;
	int width;
	int height;

public:
	Rectangle(int _x, int _y, int _width, int _height):
		x{ _x }, y{ _y }, height{ _height }, width{_width} {
		if (x < 0) x = 0;
		if (y < 0) y = 0;
		if (x + width > MAX_WIDTH) width = MAX_WIDTH - x;
		if (y + height > MAX_HEIGHT) height = MAX_HEIGHT - y;
	}

	Rectangle() : Rectangle(0, 0, MAX_WIDTH, MAX_HEIGHT) {
	}

	~Rectangle() {
		//cout << "I'm destructor" << endl;
	}

	void show() {
		cout << "left-top: " << x << ", " << y << endl;
		cout << "right-bottom: " << x + width << ", " << y + height << endl;
		cout << "left-bottom: " << x << ", " << y + height << endl;
		cout << "right-top: " << x + width << ", " << y << endl;

		cout << "width: " << width << endl;
		cout << "height: " << height << endl;
	}
};

class MyButton : public Rectangle {
public:
	MyButton(int x, int y) : Rectangle(x, y, 100, 20) {
	}

	void clic() {
		cout << "I am button" << endl;
	}
};

class MyLabel : public Rectangle {
private:
	const char* text;
public:
	MyLabel(int x, int y, const char* text) : Rectangle(x, y, 100, 20), text{ text } {}

	const char* get_text() {
		return text;
	}
};

class MyEditText : public Rectangle {
	char text[100];
public:
	MyEditText(int x, int y) : Rectangle(x, y, 100, 20) {}

	void set_text(const char* text) {
		strcpy_s(this->text, text);
	}

	char* get_text() {
		return text;
	}
};


class MyWindow : public Rectangle {	

	MyLabel* label1 = nullptr;
	MyLabel* label2 = nullptr;
	MyEditText* textedit = nullptr;
	MyButton* button1 = nullptr;
	MyButton* button2 = nullptr;

public:
	MyWindow() : Rectangle() {
		int* arr = new int[120];
		label1 = new MyLabel(10, 10, "Students");
		label2 = new MyLabel(300, 350, "Lessons");
		textedit = new MyEditText(this->width/2, this->height/2);
		button1 = new MyButton(500, 600);
		button2 = new MyButton(700, 600);
	}
	
	void main_loop() {
		while (true) {
			// обработка событий
		}
	}

	~MyWindow() {
		if (label1) delete label1;
		if (label2) delete label2;
		if (textedit) delete textedit;
		if (button1) delete button1;
		if (button2) delete button2;
	}
};



void test_windows() {
	int x, y, width, heigth;
	char is_repeat;
	do {
		cout << "Enter x, y, width, height: ";
		cin >> x >> y >> width >> heigth;

		Rectangle rect(x, y, width, heigth);
		rect.show();
		
		cout << "Reapet (y, n)?";
		cin >> is_repeat;
	} while (is_repeat == 'y' || is_repeat == 'Y');
}

void test_label_textedit() {
	MyLabel* label = new MyLabel(10, 10, "Hello I am Label1");
	cout << label->get_text() << endl;

	MyEditText* textedit = new MyEditText(20, 20);
	textedit->set_text(label->get_text());
	cout << textedit->get_text() << endl;

	textedit->set_text("I am textEdit");
	cout << textedit->get_text() << endl;
	
	delete textedit;
	delete label;
}

int main() {
	//test_windows();
	test_label_textedit();
}