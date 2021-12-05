#pragma once
#include "date.h"
#include <string>
#include <memory>

enum class LogicalOperation {
	And,
	Or
};

enum class Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual
};

class Node {
public:
	 virtual bool Evaluate(const Date& date, const string& event) = 0;
};
class EmptyNode : public Node{
	 bool Evaluate(const Date& date, const string& event = "")  override;
};

class EventComparisonNode : public Node {
public:
	EventComparisonNode(const Comparison& cmp, const string& value);
	bool Evaluate(const Date& date, const string& event)  override;
private:
	const Comparison Cmp;
	const string Event;
};

class DateComparisonNode : public Node {
public:
	DateComparisonNode(Comparison cmp, Date date);
	bool Evaluate(const Date& date, const std::string& event) override;
private:
	Comparison cmp_;
	Date date_;
};


class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(const LogicalOperation& operation, const shared_ptr<Node>&left, const shared_ptr<Node>& right);
	bool Evaluate(const Date& date, const string& event)  override;
private:
	LogicalOperation Operation;
	shared_ptr<Node> Left, Right;
};
