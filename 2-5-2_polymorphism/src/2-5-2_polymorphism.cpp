#include <iostream>
#include <string>
using namespace std;


class INotifier {
public:
	const string address;
	INotifier(const string& a) : address(a) {}
	virtual void Notify(const string& message) = 0;
};

class SmsNotifier : public INotifier {
public:
	SmsNotifier(const string& a) : INotifier(a) {}
	void Notify(const string& message) override {
		cout << "Send '" << message << "' to number "  << address << endl;
	}
};

class EmailNotifier : public INotifier {
public:
	EmailNotifier(const string& a) : INotifier(a) {}
	void Notify(const string& message) override {
		cout << "Send '" << message << "' to e-mail "  << address << endl;
	}
};

void Notify(INotifier& notifier, const string& message) {
  notifier.Notify(message);
}

int main() {
	SmsNotifier sms{"+7-495-777-77-77"};
	EmailNotifier email{"na-derevnyu@dedushke.ru"};

	Notify(sms, "I have White belt in C++");
	Notify(email, "And want a Yellow one");
	return 0;
}
