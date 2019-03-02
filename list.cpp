
void listAll(const MenuItem* m, string path) // two-parameter overload
{
	if (m->name() != "")
	{
		if (path != "")
			path += '/';
		path += m->name();
		cout << path << endl;
	}

	if (m->menuItems() == nullptr || m->menuItems()->empty())
		return;
	
	for (int i = 0; i < m->menuItems()->size(); i++)
		listAll((*m->menuItems())[i], path);
}
