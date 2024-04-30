#include "DxLib.h"
#include "File.h"

File::File()
{
	fp = nullptr;
	err = 0;
}
File::~File()
{
	CloseFile();
}

bool File::OpenFile(const char* file_name, const char* open_type)
{
	err = fopen_s(&fp, file_name, open_type);

	if (err == NULL) {
		return true;
	}
	return false;
}

void File::CloseFile()
{
	if (fp != nullptr) {
		fclose(fp);
		fp = nullptr;
		err = 0;
	}
}