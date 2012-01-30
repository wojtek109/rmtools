#ifndef MI_MEMORYSTREAMBASE_H_INCLUDED
#define MI_MEMORYSTREAMBASE_H_INCLUDED

template< mEStreamType M >
class mTMemoryStreamBase :
    public mCIStream< M >,
    public mCOStream< M >,
    public mCStreamSeekable
{
public:
    virtual ~mTMemoryStreamBase( void );
public:
    mTMemoryStreamBase( void );
    mTMemoryStreamBase( mTMemoryStreamBase< M > const & a_Source );
    mTMemoryStreamBase( mCStreamSeekable & a_Source );
public:
    mTMemoryStreamBase< M > & operator = ( mTMemoryStreamBase< M > const & a_Source );
public:
    virtual MIUInt   GetSize( void ) const;
    virtual mEResult Read( MILPVoid a_pDest, MIUInt a_uSize );
    virtual mEResult Read( mCString & a_strDest, MIUInt a_uSize );
    virtual mEResult Read( mCString & a_strDest ) = 0;
    virtual mEResult Seek( MIUInt a_uPosition, mEStreamSeekMode a_enuMode = mEStreamSeekMode_Begin );
    virtual MIUInt   Tell( void ) const;
    virtual mEResult Write( MILPCVoid a_pSource, MIUInt a_uSize );
    virtual mEResult Write( mCString const & a_strSource );
public:
    void     Clear( void );
    mEResult FromFile( mCString a_strFileName );
    mEResult ToFile( mCString a_strFileName );
    void     Swap( mTMemoryStreamBase< M > & a_Other );
private:
    virtual mEResult ReadFormatted( MILPVoid a_pDest, MILPCChar a_Format ) = 0;
    virtual mEResult WriteFormatted( MILPCVoid a_pSource, MILPCChar a_Format ) = 0;
protected:
    mCCharArray m_arrBuffer;
    MIUInt      m_uPosition;
};

typedef mTMemoryStreamBase< mEStreamType_Binary >    mCMemoryStreamBaseBinary;
typedef mTMemoryStreamBase< mEStreamType_Formatted > mCMemoryStreamBaseFormatted;

#endif