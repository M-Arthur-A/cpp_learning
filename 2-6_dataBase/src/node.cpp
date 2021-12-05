#include "node.h"
#include "date.h"

bool EmptyNode::Evaluate(const Date& date, const string& event)  {
	return true;
}

EventComparisonNode::EventComparisonNode(const Comparison& cmp, const string& value)
	:Cmp(cmp),
	Event(value){
}

bool EventComparisonNode::Evaluate(const Date& date, const string& event)  {
	if (Cmp == Comparison::Less) {
		return event < Event;
	}
	else if (Cmp == Comparison::LessOrEqual) {
		return event <= Event;
	}
	else if (Cmp == Comparison::Greater) {
		return (event > Event);
	}
	else if (Cmp == Comparison::GreaterOrEqual) {
		return (event >= Event);
	}
	else if (Cmp == Comparison::Equal) {
		return event == Event;
	}
	else if (Cmp == Comparison::NotEqual) {
		return !(event == Event);
	}
	cout << "Mistake in EventComparisonNode::Evaluate" << endl;
	return false;
}



DateComparisonNode:: DateComparisonNode(Comparison cmp, Date date)
		: cmp_(cmp)
		, date_(date) {}

bool DateComparisonNode::Evaluate(const Date& date, const std::string& event){
	switch (cmp_) {
		case Comparison::Less:
			return date < date_;
		case Comparison::LessOrEqual:
			return date <= date_;
		case Comparison::Greater:
			return date > date_;
		case Comparison::GreaterOrEqual:
			return date >= date_;
		case Comparison::Equal:
			return date == date_;
		case Comparison::NotEqual:
			return !(date == date_);
	}
}




LogicalOperationNode::LogicalOperationNode(const LogicalOperation& operation, const shared_ptr<Node>&left, const shared_ptr<Node>& right)
	:Operation(operation),
	Left(left),
	Right(right){
}

bool LogicalOperationNode::Evaluate(const Date& date, const string& s) {
	bool result = false;
	if (Operation == LogicalOperation::And) {
		result = Left->Evaluate(date, s) && Right->Evaluate(date, s);
	}
	else if (Operation == LogicalOperation::Or) {
		result = Left->Evaluate(date, s) || Right->Evaluate(date, s);
	}
	return result;
}
