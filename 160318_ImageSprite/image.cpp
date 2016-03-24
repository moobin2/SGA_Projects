#include "stdafx.h"
#include "image.h"

#pragma comment( lib, "msimg32.lib" )

image::image( ) :
_imageInfo( NULL ),
_blendImage(NULL),
_fileName( NULL ),
_trans( false ),
_transColor( RGB( 0, 0, 0 ) )
{
}


image::~image()
{
}

//�� ��Ʈ��  �̹��� �����
HRESULT image::init( int width, int height )
{
	//�ʱ�ȭ�� �ٽ� �Ǵ� ���� ����
	if ( _imageInfo != NULL ) release( );

	//DC ���´�
	HDC hdc = GetDC( _hWnd );

	//CreateCompatibleDC
	//��Ʈ���� ����ϱ� ���ؼ� �޸� DC�� ����� �ִ� ��

	//CreateCompatibleBitMap
	//���� DC�� ȣȯ�Ǵ� ��Ʈ�� ����

	//�̹��� ���� ����
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_EMPTY;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC( hdc );
	_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap( hdc, width, height );
	_imageInfo->hOBit = (HBITMAP)SelectObject( _imageInfo->hMemDC, _imageInfo->hBit );
	_imageInfo->width = width;
	_imageInfo->height = height;

	_fileName = NULL;

	//���� �÷� ����
	_trans = FALSE;
	_transColor = RGB( 0, 0, 0 );

	//���� ���� ��� ��������
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;

	//���� ���� ����� ���� �̹��� ����
	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_EMPTY;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;
	
	//���� DC ����
	ReleaseDC( _hWnd, hdc );

	//���ҽ� ������ ���н� ó��
	if ( _imageInfo->hBit == 0 )
	{
		release( );

		return E_FAIL;
	}

	return S_OK;
}

//���ҽ��κ��� �о�´�
HRESULT image::init( const DWORD resID, int width,
	int height, BOOL trans, COLORREF transColor )
{
	//���ʱ�ȭ�� ���
	if ( _imageInfo != NULL ) release( );

	//DC ��´�
	HDC hdc = GetDC( _hWnd );

	//�̹��� ���� ����
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_RESOURCE;
	_imageInfo->resID = resID;
	_imageInfo->hMemDC = CreateCompatibleDC( hdc );
	_imageInfo->hBit = (HBITMAP)LoadBitmap( _hInstance, MAKEINTRESOURCE( _imageInfo->resID ) );
	_imageInfo->hOBit = (HBITMAP)SelectObject( _imageInfo->hMemDC, _imageInfo->hBit );
	_imageInfo->width = width;
	_imageInfo->height = height;

	_fileName = NULL;

	//���� �÷� ����
	_trans = FALSE;
	_transColor = RGB( 0, 0, 0 );

	//���� ���� ��� ��������
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;

	//���� ���� ����� ���� �̹��� ����
	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_EMPTY;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;

	//���� DC ����
	ReleaseDC( _hWnd, hdc );

	//���ҽ� ��⿡ �����ϸ�
	if ( _imageInfo->hBit == 0 )
	{
		release( );
		return E_FAIL;
	}

	return S_OK;
}


//�̹��� ���� (���Ϸκ��� �о�´�)
HRESULT image::init( const char* fileName, int width, int height,
	BOOL trans, COLORREF transColor )
{
	//���� ��ΰ� �߸� �Ǿ�����...
	if ( fileName == NULL ) return E_FAIL;

	//���ʱ�ȭ�� ���
	if ( _imageInfo != NULL ) release( );

	//DC ��´�
	HDC hdc = GetDC( _hWnd );

	//�̹��� ���� ����
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC( hdc );
	_imageInfo->hBit = (HBITMAP)LoadImage( _hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE );
	_imageInfo->hOBit = (HBITMAP)SelectObject( _imageInfo->hMemDC, _imageInfo->hBit );
	_imageInfo->width = width;
	_imageInfo->height = height;

	//���� ��� �̸� ����
	int len = strlen( fileName );
	_fileName = new CHAR[len + 1];
	strcpy_s( _fileName, len + 1, fileName );

	//���� �÷� ����
	_trans = trans;
	_transColor = transColor;

	//���� ���� ��� ��������
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;

	//���� ���� ����� ���� �̹��� ����
	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_EMPTY;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;

	//���� DC����
	ReleaseDC( _hWnd, hdc );

	//���ҽ� ��⿡ �����ϸ�
	if ( _imageInfo->hBit == 0 )
	{
		release( );
		return E_FAIL;
	}

	return S_OK;
}

//����
void image::release( void )
{
	if (_imageInfo)
	{
		//�̹��� ����
		SelectObject(_imageInfo->hMemDC, _imageInfo->hOBit);
		DeleteObject(_imageInfo->hBit);
		DeleteDC(_imageInfo->hMemDC);

		//������ ����
		SAFE_DELETE(_imageInfo);
		SAFE_DELETE(_fileName);

		//���� �÷� �ʱ�ȭ
		_trans = false;
		_transColor = RGB(0, 0, 0);
	}

	if (_blendImage)
	{
		SelectObject(_blendImage->hMemDC, _blendImage->hOBit);
		DeleteObject(_blendImage->hBit);
		DeleteDC(_blendImage->hMemDC);

		SAFE_DELETE(_blendImage);
	}
}

//���� Ű��(RGB��) ���� == Ư�� ������ �׸��� �ʴ´�
void image::setTransColor( BOOL trans, COLORREF transColor )
{
	_trans = trans;
	_transColor = transColor;
}

//����
void image::render( HDC hdc, int destX, int destY )
{
	if (_trans)
	{
		GdiTransparentBlt(
			hdc,				//������ ����� DC
			destX,				//����� ��ǥ ����X
			destY,				//����� ��ǥ ����Y
			_imageInfo->width,	//����� ũ�� width
			_imageInfo->height,	//����� ũ�� height
			_imageInfo->hMemDC,	//������ DC
			0, 0,				//���� �������� x, y
			_imageInfo->width,	//������ ũ�� width
			_imageInfo->height,	//������ ũ�� height
			_transColor);		//���翡�� ������ ����
	}
	else
	{
		BitBlt(hdc, destX, destY, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

void image::render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight)
{
	if (_trans)
	{
		GdiTransparentBlt(
			hdc,				//������ ����� DC
			destX,				//����� ��ǥ ����X
			destY,				//����� ��ǥ ����Y
			sourWidth,			//����� ũ�� width
			sourHeight,			//����� ũ�� height
			_imageInfo->hMemDC,	//������ DC
			sourX, sourY,		//���� �������� x, y
			sourWidth,			//������ ũ�� width
			sourHeight,			//������ ũ�� height
			_transColor);		//���翡�� ������ ����
	}
	else
	{
		BitBlt(hdc, destX, destY, sourWidth, sourHeight,
			_imageInfo->hMemDC, sourX, sourY, SRCCOPY);
	}
}

void image::alphaRender(HDC hdc, int destX, int destY, BYTE alpha)
{
	_blendFunc.SourceConstantAlpha = alpha;

	if (_trans)   //trans => Ư���� �����Ҳ���?
				  //alpha => �׸���ü�� �����ϰ� �Ҳ���?
				  
	{
		//����ؾ� �� DC�� �׷��� �ִ� ������ blend�� �׷��ش�
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			hdc, destX, destY, SRCCOPY);

		//����ؾ� �� �̹����� blend�� �׷��ش�
		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0,
			_imageInfo->width, _imageInfo->height, _transColor);

		//blendDC�� ����ؾ� �� DC�� �׸���
		AlphaBlend(hdc, destX, destY, _imageInfo->width, _imageInfo->height,
			_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
	else // Ʈ������ �ƴҶ� (false�϶�)
	{
		AlphaBlend(hdc, destX, destY, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
}


void image::alphaRender(HDC hdc, int destX, int destY, int sourX, int sourY,
	int sourWidth, int sourHeight, BYTE alpha)
{
	_blendFunc.SourceConstantAlpha = alpha;

	if (_trans)   //trans => Ư���� �����Ҳ���?
				  //alpha => �׸���ü�� �����ϰ� �Ҳ���?

	{
		//����ؾ� �� DC�� �׷��� �ִ� ������ blend�� �׷��ش�
		BitBlt(_blendImage->hMemDC, 0, 0, sourWidth, sourHeight, hdc, destX, destY, SRCCOPY);

		//����ؾ� �� �̹����� blend�� �׷��ش�
		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, sourWidth, sourHeight, 
			_imageInfo->hMemDC, sourX, sourY, sourWidth, sourHeight, _transColor);

		//blendDC�� ����ؾ� �� DC�� �׸���
		AlphaBlend(hdc, destX, destY, sourWidth, sourHeight, 
			_blendImage->hMemDC, 0, 0, sourWidth, sourHeight, _blendFunc);
	}
	else // Ʈ������ �ƴҶ� (false�϶�)
	{
		AlphaBlend(hdc, destX, destY, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
}