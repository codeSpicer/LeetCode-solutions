basic idea is to first go to the next pointer if the head contain the target
​
then if the next value has target value then we make the current pointers next the next.next node.
​
for cases like node->target->target->target->node
​
once the next node doesnt have target value we do ptr->next