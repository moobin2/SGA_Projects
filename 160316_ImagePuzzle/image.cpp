#include "stdafx.h"
#include "image.h"

#pragma comment( lib, "msimg32.lib" )

image::image( ) :_imageInfo( NULL ),_fileName( NULL ),_trans( false ),_transColor( RGB( 0, 0, 0 ) )
{
}


image::~image()
{
}

//빈 비트맵  이미지 만든다
HRESULT image::init( int width, int height )
{
	//초기화가 다시 되는 것을 방지
	if ( _imageInfo != NULL ) release( );

	//DC 얻어온다
	HDC hdc = GetDC( _hWnd );

	//CreateCompatibleDC
	//비트맵을 출력하기 위해서 메모리 DC를 만들어 주는 것

	//CreateCompatibleBitMap
	//원본 DC와 호환되는 비트맵 생성

	//이미지 정보 생성
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_EMPTY;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC( hdc );
	_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap( hdc, width, height );
	_imageInfo->hOBit = (HBITMAP)SelectObject( _imageInfo->hMemDC, _imageInfo->hBit );
	_imageInfo->width = width;
	_imageInfo->height = height;

	_fileName = NULL;

	//투명 컬러 셋팅
	_trans = FALSE;
	_transColor = RGB( 0, 0, 0 );


	//얻은 DC 해제
	ReleaseDC( _hWnd, hdc );

	//리소스 얻어오기 실패시 처리
	if ( _imageInfo->hBit == 0 )
	{
		release( );
		return E_FAIL;
	}

	return S_OK;
}

//리소스로부터 읽어온다
HRESULT image::init( const DWORD resID, int width, int height, BOOL trans, COLORREF transColor )
{
	//재초기화에 대비
	if ( _imageInfo != NULL ) release( );

	//DC 얻는다
	HDC hdc = GetDC( _hWnd );

	//이미지 정보 생성
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_RESOURCE;
	_imageInfo->resID = resID;
	_imageInfo->hMemDC = CreateCompatibleDC( hdc );
	_imageInfo->hBit = (HBITMAP)LoadBitmap( _hInstance, MAKEINTRESOURCE( _imageInfo->resID ) );
	_imageInfo->hOBit = (HBITMAP)SelectObject( _imageInfo->hMemDC, _imageInfo->hBit );
	_imageInfo->width = width;
	_imageInfo->height = height;

	_fileName = NULL;

	//투명 컬러 셋팅
	_trans = FALSE;
	_transColor = RGB( 0, 0, 0 );

	//얻은 DC 해제
	ReleaseDC( _hWnd, hdc );

	//리소스 얻기에 실패하면
	if ( _imageInfo->hBit == 0 )
	{
		release( );
		return E_FAIL;
	}

	return S_OK;
}


//이미지 설정 (파일로부터 읽어온다)
HRESULT image::init( const char* fileName, int width, int height, BOOL trans, COLORREF transColor )
{
	//파일 경로가 잘못 되었으면...
	if ( fileName == NULL ) return E_FAIL;

	//재초기화에 대비
	if ( _imageInfo != NULL ) release( );

	//DC 얻는다
	HDC hdc = GetDC( _hWnd );

	//이미지 정보 생성
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC( hdc );
	_imageInfo->hBit = (HBITMAP)LoadImage( _hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE );
	_imageInfo->hOBit = (HBITMAP)SelectObject( _imageInfo->hMemDC, _imageInfo->hBit );
	_imageInfo->width = width;
	_imageInfo->height = height;

	//파일 경로 이름 복사
	int len = strlen( fileName );
	_fileName = new CHAR[len + 1];
	strcpy_s( _fileName, len + 1, fileName );

	//투명 컬러 셋팅
	_trans = trans;
	_transColor = transColor;

	//얻은 DC해제
	ReleaseDC( _hWnd, hdc );

	//리소스 얻기에 실패하면
	if ( _imageInfo->hBit == 0 )
	{
		release( );
		return E_FAIL;
	}

	return S_OK;
}

//삭제
void image::release( void )
{
	if (_imageInfo)
	{
		//이미지 삭제 (원래 있던거 원상복귀)
		SelectObject(_imageInfo->hMemDC, _imageInfo->hOBit);
		DeleteObject(_imageInfo->hBit);
		DeleteDC(_imageInfo->hMemDC);

		//포인터 삭제
		SAFE_DELETE(_imageInfo);
		SAFE_DELETE(_fileName);

		//투명 컬러 초기화
		_trans = false;
		_transColor = RGB(0, 0, 0);
	}
}

//투명 키값(RGB값) 셋팅 == 특정 색상을 그리지 않는다
void image::setTransColor( BOOL trans, COLORREF transColor )
{
	_trans = trans;
	_transColor = transColor;
}

//렌더
void image::render( HDC hdc, int destX, int destY )
{
	if (_trans)
	{
		GdiTransparentBlt(
			hdc,				//복사할 장소의 DC
			destX,				//복사될 좌표 시작X
			destY,				//복사될 좌표 시작Y
			_imageInfo->width,	//복사될 크기 width
			_imageInfo->height,	//복사될 크기 height
			_imageInfo->hMemDC,	//복사할 DC
			0, 0,				//복사 시작지점 x, y
			_imageInfo->width,	//복사할 크기 width
			_imageInfo->height,	//복사할 크기 height
			_transColor);		//복사에서 제외할 색상
	}
	else
	{
		BitBlt(hdc, destX, destY, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

// 원하는 크기로 키워주는 랜더함수 
void image::render(HDC hdc, int destX, int destY , int Width, int Height)
{
	if (_trans)
	{
		GdiTransparentBlt(
			hdc,				//복사할 장소의 DC
			destX,				//복사될 좌표 시작X
			destY,				//복사될 좌표 시작Y
			Width,				//복사될 크기 width
			Height,				//복사될 크기 height
			_imageInfo->hMemDC,	//복사할 DC
			0, 0,				//복사 시작지점 x, y
			_imageInfo->width,	//복사할 크기 width
			_imageInfo->height,	//복사할 크기 height
			_transColor);		//복사에서 제외할 색상
	}
	else
	{
		BitBlt(hdc, destX, destY, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

// 렉터위 그려주는 함수.
void image::render(HDC hdc, RECT rc, int num)
{
	int width = rc.right - rc.left;
	int height = rc.bottom - rc.top;
	if (_trans)
	{
		GdiTransparentBlt(
			hdc,				//복사할 장소의 DC
			rc.left,			//복사될 좌표 시작X
			rc.top,				//복사될 좌표 시작Y
			width,				//복사될 크기 width
			height,				//복사될 크기 height
			_imageInfo->hMemDC,	//복사할 DC
			(num % 4) * width,
			(num / 4) * height,
			width,				//복사할 크기 width
			height,				//복사할 크기 height
			_transColor);		//복사에서 제외할 색상
	}
	else
	{
		BitBlt(hdc, rc.left, rc.top, width, height, _imageInfo->hMemDC,  (num % 4) * width, (num / 4) * height, SRCCOPY);
	}
}
