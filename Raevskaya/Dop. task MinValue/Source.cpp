struct Node* minValueNode(struct Node* node)
{
	struct Node* current = node;
	struct Node* result;

	while (current->l->l != NULL)
		current = current->l;

	result = current->l;
	current->l = NULL;
	return result;
}