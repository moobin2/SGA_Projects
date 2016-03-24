#pragma once

class image
{
public:
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE = 0,      //���ҽ��κ��� ����
		LOAD_FILE,              //���Ϸκ��� ����
		LOAD_EMPTY,             //�� ����
		LOAD_END
	};

	typedef struct tagImageInfo
	{
		DWORD resID;
		HDC hMemDC;
		HBITMAP hBit;
		HBITMAP hOBit;
		int width;
		int height;
		BYTE loadType;

		tagImageInfo( )
		{
			resID = 0;
			hMemDC = NULL;
			hBit = NULL;
			hOBit = NULL;
			width = 0;
			height = 0;
			loadType = LOAD_RESOURCE;
		}
	} IMAGE_INFO, *LPIMAGE_INFO;

private:
	//������ ���ÿ� ����̴ϼ� ������� �ʱ�ȭ ���ִ� ������
	LPIMAGE_INFO    _imageInfo;        //�̹��� ����
	CHAR*           _fileName;         //�̹��� ��� �̸�

	BOOL            _trans;             //�������̳�?
	COLORREF        _transColor;       //�����÷�Ű
	
	BLENDFUNCTION	_blendFunc;			//���� ���带 ���� ����
	LPIMAGE_INFO	_blendImage;		//���� ���带 ����ϱ� ���� �̹��� ����



public:
	image( );
	~image( );

	//�� ��Ʈ�� �̹��� �����
	HRESULT init( int width, int height );

	//���ҽ��κ��� �о��
	HRESULT init( const DWORD resID, int width, int height,	BOOL trans, COLORREF transColor);

	//�̹��� ���� (���Ϸ� �о��)
	HRESULT init( const char* fileName, int width, int height, BOOL trans, COLORREF transColor);

	//����
	void release( void );

	//���� Ű��(RGB��) ���� == Ư�� ������ �׸��� �ʴ´�
	void setTransColor(BOOL trans, COLORREF transColor);

	//����
	void render( HDC hdc, int destX, int destY );
	void render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	//���� ����
	void alphaRender(HDC hdc, int destX, int destY, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);

	//DC������
	inline HDC getMemDC( void ) { return _imageInfo->hMemDC; }
};
