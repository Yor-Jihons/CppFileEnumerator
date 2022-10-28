#ifndef YOR_OBJECTIVEFILEENUMCPP_ENUMREUSLT_H
#define YOR_OBJECTIVEFILEENUMCPP_ENUMREUSLT_H

#include<string>
#include<windows.h>
#include<memory>
#include"EnumTypes.h"

#define UNICODE

namespace CppFileEnumerators{
    class EnumResult{
        public:
            static std::unique_ptr<EnumResult> Create( WIN32_FIND_DATAW fd );

            ~EnumResult();

            std::wstring FileName( void ) const;

            EnumTypes::EnumType Type( void ) const;

            bool IsReadOnly( void ) const;

        private:
            EnumResult( const std::wstring& fileName, EnumTypes::EnumType type, bool isReadOnly );
        private:
            std::wstring m_fileName;
            EnumTypes::EnumType m_type;
            bool m_isReadOnly;
    };
}

#endif
