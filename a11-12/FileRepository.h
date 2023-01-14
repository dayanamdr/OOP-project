#pragma once

#include "MemoryRepository.h"

class FileRepository : public MemoryRepository {
private:
	string filename;
	void loadFromFile();

public:
	FileRepository();
	FileRepository(const string& filename);
	~FileRepository();

	void saveToFile() override;
};