#include "node.h"
int main()
{
	List <int> data;

	// Node 추가
	data.AddNode(1);
	data.AddNode(2);
	data.AddNode(5);
	data.AddHead(3);
	data.AddHead(4);

	// Node 확인
	data.Show();

	// Node 삭제
	data.RemoveHead();
	data.RemoveTail();

	// Node 확인
	data.Show();

	// Node 사이즈 확인
	data.Size();

	// Node 전체 삭제
	data.DeleteList();
	
	// Node 추가
	data.AddNode(3);

	// Node 검색
	data.SearchValue(3);

	// Test 결과 : AddPosition이 현재 데이터가 아예 없을때 제대로 된 데이터를 추가하지 못함.

}
