weird thing is how we dont need to add the values of bst to the set before hand because we want to check for a pair of nodes.
​
so even if when we find the first node there is no target-first->val but when we encounter the pair node of first with adds up to the target then we can find target-second->val , which will then be first->val that is already in the set.