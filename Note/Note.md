# 이곳은 DirectX 필기하는 공간입니다.

## ⚙ DirectX 프로젝트 초기 설정 ⚙

### 속성
- 포함 디렉터리
- 라이브러리 디렉터리 설정  
- 추가 포함 디렉터리
  - 링커 -> 입력에서 
  - ```C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Samples\C++\Direct3D\Tutorials```
  - 에서 추가 종속성 가져오기

### 코드 
- WndProc에서 WM_COMMED 삭제
- CALLBACK About 삭제
- MyRegisterClass에서  wcex.lpszMenuName   = nullptr; ... menu 부분을 없애준다.
- InitInstance에서 InitD3D()를 추가해준다.
- wWinMain에서 ```C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Samples\C++\Direct3D\Tutorials``` 을 보고 따라한다. 
- InitInstance에서 init3d()를 호출해준다.
- HwND 초기화 할 때 window_width, window_height를 지정한다.
- wWinMain에서 update()와 render()를 추가한다.