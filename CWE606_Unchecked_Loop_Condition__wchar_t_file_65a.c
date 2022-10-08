/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE606_Unchecked_Loop_Condition__wchar_t_file_65a.c
Label Definition File: CWE606_Unchecked_Loop_Condition.label.xml
Template File: sources-sinks-65a.tmpl.c
*/
/*
 * @description
 * CWE: 606 Unchecked Input For Loop Condition
 * BadSource: file Read input from a file
 * GoodSource: Input a number less than MAX_LOOP
 * Sinks:
 *    GoodSink: Use data as the for loop variant after checking to see if it is less than MAX_LOOP
 *    BadSink : Use data as the for loop variant without checking its size
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#define MAX_LOOP 10000

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE606_Unchecked_Loop_Condition__wchar_t_file_65b_badSink(wchar_t * data);

void CWE606_Unchecked_Loop_Condition__wchar_t_file_65_bad()
{
    wchar_t * data;
    /* define a function pointer */
    void (*funcPtr) (wchar_t *) = CWE606_Unchecked_Loop_Condition__wchar_t_file_65b_badSink;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    {
        /* Read input from a file */
        size_t dataLen = wcslen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if (100-dataLen > 1)
        {
            pFile = fopen(FILENAME, "r");
            if (pFile != NULL)
            {
                /* POTENTIAL FLAW: Read data from a file */
                if (fgetws(data+dataLen, (int)(100-dataLen), pFile) == NULL)//SLIVER_SOURCE
                {
                    printLine("fgetws() failed");
                    /* Restore NUL terminator if fgetws fails */
                    data[dataLen] = L'\0';
                }
                fclose(pFile);
            }
        }
    }
    /* use the function pointer */
    funcPtr(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE606_Unchecked_Loop_Condition__wchar_t_file_65b_goodG2BSink(wchar_t * data);

static void goodG2B()
{
    wchar_t * data;
    void (*funcPtr) (wchar_t *) = CWE606_Unchecked_Loop_Condition__wchar_t_file_65b_goodG2BSink;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    /* FIX: Set data to a number less than MAX_LOOP */
    wcscpy(data, L"15");
    funcPtr(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE606_Unchecked_Loop_Condition__wchar_t_file_65b_goodB2GSink(wchar_t * data);

static void goodB2G()
{
    wchar_t * data;
    void (*funcPtr) (wchar_t *) = CWE606_Unchecked_Loop_Condition__wchar_t_file_65b_goodB2GSink;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    {
        /* Read input from a file */
        size_t dataLen = wcslen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if (100-dataLen > 1)
        {
            pFile = fopen(FILENAME, "r");
            if (pFile != NULL)
            {
                /* POTENTIAL FLAW: Read data from a file */
                if (fgetws(data+dataLen, (int)(100-dataLen), pFile) == NULL)//SLIVER_SOURCE
                {
                    printLine("fgetws() failed");
                    /* Restore NUL terminator if fgetws fails */
                    data[dataLen] = L'\0';
                }
                fclose(pFile);
            }
        }
    }
    funcPtr(data);
}

void CWE606_Unchecked_Loop_Condition__wchar_t_file_65_good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE606_Unchecked_Loop_Condition__wchar_t_file_65_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE606_Unchecked_Loop_Condition__wchar_t_file_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif


//SLIVER_SOURCE:CWE606_Unchecked_Loop_Condition__wchar_t_file_65a.c:55--->SLIVER_SINK:CWE606_Unchecked_Loop_Condition__wchar_t_file_65b.c:42 YES
//SLIVER_SOURCE:CWE606_Unchecked_Loop_Condition__wchar_t_file_65a.c:55--->SLIVER_SINK:CWE606_Unchecked_Loop_Condition__wchar_t_file_65b.c:65 NO
//SLIVER_SOURCE:CWE606_Unchecked_Loop_Condition__wchar_t_file_65a.c:55--->SLIVER_SINK:CWE606_Unchecked_Loop_Condition__wchar_t_file_65b.c:86 NO
//SLIVER_SOURCE:CWE606_Unchecked_Loop_Condition__wchar_t_file_65a.c:107--->SLIVER_SINK:CWE606_Unchecked_Loop_Condition__wchar_t_file_65b.c:42 NO
//SLIVER_SOURCE:CWE606_Unchecked_Loop_Condition__wchar_t_file_65a.c:107--->SLIVER_SINK:CWE606_Unchecked_Loop_Condition__wchar_t_file_65b.c:65 NO
//SLIVER_SOURCE:CWE606_Unchecked_Loop_Condition__wchar_t_file_65a.c:107--->SLIVER_SINK:CWE606_Unchecked_Loop_Condition__wchar_t_file_65b.c:86 YES
