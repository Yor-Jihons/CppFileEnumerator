#include<iostream>
#include<vector>
#include<memory>
#include<random>

#include"./../../lib/bin/CppFileEnumerators.h"

using std::cout;
using std::endl;
using std::flush;

namespace Console{
    void SetLocale( const std::string& localeName = "Japanese" ){
        setlocale( LC_ALL, const_cast<char*>(localeName.c_str()) );
    }
    void Print( const std::wstring& text = L"\n" ){
        wprintf( L"%S", const_cast<wchar_t*>(text.c_str()) );
    }
} // namespace Console


int main( int argc, char** argv ){
    Console::SetLocale();

    std::wstring target = L"*.*";
    std::unique_ptr<CppFileEnumerators::FileEnumerator> enumerator = std::make_unique<CppFileEnumerators::FileEnumerator>( target );

    auto first = enumerator->FindFirst();
    if( !std::get<0>( first ) ){
        Console::Print( L"Error 1" );
        return -1;
    }

    Console::Print( std::get<1>( first )->FileName() );

    if( std::get<1>( first )->IsReadOnly() ) Console::Print( L" is read-only" );
    else Console::Print( L"is not read-only" );

    Console::Print();

    while( true ){
        auto next = enumerator->FindNext();
        if( !std::get<0>( next ) ){
            break;
        }

        Console::Print( std::get<1>( next )->FileName() );

        if( std::get<1>( next )->IsReadOnly() ) Console::Print( L" is read-only" );
        else Console::Print( L" is not read-only" );

        Console::Print();
    }
return 0;
}
