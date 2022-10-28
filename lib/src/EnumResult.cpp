#include"EnumResult.h"

namespace CppFileEnumerators{
    std::unique_ptr<EnumResult> EnumResult::Create( WIN32_FIND_DATAW fd ){
        std::wstring fileName = fd.cFileName;

        bool isReadOnly = false;
        if( fd.dwFileAttributes & FILE_ATTRIBUTE_READONLY ) isReadOnly = true;
        DWORD d = GetFileAttributesW( fd.cFileName );

        EnumTypes::EnumType type = EnumTypes::Unknown;
        if( fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ){
            type = EnumTypes::Directory;
        }else{
            type = EnumTypes::File;
        }
    return std::move( std::unique_ptr<EnumResult>(new EnumResult( fileName, type, isReadOnly ) ) );
    }

    EnumResult::EnumResult( const std::wstring& fileName, EnumTypes::EnumType type, bool isReadOnly )
    : m_fileName(fileName),m_type(type){

    }

    EnumResult::~EnumResult(){

    }

    std::wstring EnumResult::FileName( void ) const{
        return this->m_fileName;
    }

    EnumTypes::EnumType EnumResult::Type( void ) const{
        return this->m_type;
    }

    bool EnumResult::IsReadOnly( void ) const{
        return this->m_isReadOnly;
    }
}
