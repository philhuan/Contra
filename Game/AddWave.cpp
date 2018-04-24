#include "AddWave.h"

AddWave::AddWave()
{
}

AddWave::~AddWave()
{
}

void AddWave::addList()
{
	//在这个数组里面添加数据,注意：数据从0开始,add方法可添加数组

	page = 0;
	{
		setStartPosition(80, 400);
		int list1[] = { 0,0,0,0,0,0,0
		};
		add(list1, sizeof(list1) / sizeof(int));

		setStartPosition(400, 430);
		int list2[] = { 1,2,1,2,1,2,1,2
		};
		add(list2, sizeof(list2) / sizeof(int));
	}
	page = 1;
	{
		setStartPosition(80, 460);
		int list1[] = { 1,2,1,2
		};
		add(list1, sizeof(list1) / sizeof(int));

		setStartPosition(240, 430);
		int list2[] = { 1,2
		};
		add(list2, sizeof(list2) / sizeof(int));

		setStartPosition(400, 435);
		int list3[] = { 1,2,1,2
		};
		add(list3, sizeof(list3) / sizeof(int));

		setStartPosition(600, 395);
		int list4[] = { 0,0,0,0
		};
		add(list4, sizeof(list4) / sizeof(int));
	}
	page = 2;
	{
		setStartPosition(160, 430);
		int list1[] = { 1,2
		};
		add(list1, sizeof(list1) / sizeof(int));

		setStartPosition(240, 465);
		int list2[] = { 1,2,1,2
		};
		add(list2, sizeof(list2) / sizeof(int));

		setStartPosition(400, 430);
		int list3[] = { 1,2,1,2
		};
		add(list3, sizeof(list3) / sizeof(int));

		setStartPosition(600, 395);
		int list4[] = { 0
		};
		add(list4, sizeof(list4) / sizeof(int));
	}
	page = 3;
	{
		setStartPosition(320, 400);
		int list1[] = { 0,0,0,0,0,0,0,0,0,0
		};
		add(list1, sizeof(list1) / sizeof(int));
	}
	page = 4;
	{
		setStartPosition(400, 395);
		int list1[] = { 0,0,0
		};
		add(list1, sizeof(list1) / sizeof(int));

		setStartPosition(560, 430);
		int list2[] = { 1,2
		};
		add(list2, sizeof(list2) / sizeof(int));
	}
	page = 5;
	{
		setStartPosition(0, 430);
		int list1[] = { 1,2,1,2,1,2,1,2
		};
		add(list1, sizeof(list1) / sizeof(int));

		setStartPosition(320, 460);
		int list2[] = { 1,2,1,2,1,2
		};
		add(list2, sizeof(list2) / sizeof(int));

		setStartPosition(560, 430);
		int list3[] = { 1,2,1,2
		};
		add(list3, sizeof(list3) / sizeof(int));
	}

	page = 6;
	{
		setStartPosition(160, 430);
		int list1[] = { 1,2,1,2,1,2,1,2
		};
		add(list1, sizeof(list1) / sizeof(int));

		setStartPosition(480, 460);
		int list2[] = { 1,2
		};
		add(list2, sizeof(list2) / sizeof(int));
	}
	

}
