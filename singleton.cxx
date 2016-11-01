
#include <singleton.hxx>
#include <com/sun/star/uno/XComponentContext.hpp>
#include <cppuhelper/supportsservice.hxx>
#include <uno/lbnames.h>

using namespace ::rtl; // for OUString
using namespace ::com::sun::star; // for sdk interfaces
using namespace ::com::sun::star::uno; // for basic types


#define SERVICE_NAME "inco.niocs.test.BoolDataStore"

// DataStoreImpl : XServiceInfo
OUString SAL_CALL BoolDataStoreImpl::getImplementationName()
    throw (RuntimeException)
{
    return IMPLEMENTATION_NAME;
}

sal_Bool SAL_CALL BoolDataStoreImpl::supportsService( const OUString& rServiceName )
    throw (RuntimeException)
{
    return cppu::supportsService(this, rServiceName);
}

Sequence< OUString > SAL_CALL BoolDataStoreImpl::getSupportedServiceNames(  )
    throw (RuntimeException)
{
    Sequence < OUString > aRet(1);
    OUString* pArray = aRet.getArray();
    pArray[0] =  OUString ( SERVICE_NAME );
    return aRet;
}


struct Instance {
    explicit Instance(
	Reference<XComponentContext> const & context):
	instance(
	    static_cast<cppu::OWeakObject *>(new BoolDataStoreImpl()))
    {}
    Reference<XInterface> instance;
};


struct Singleton:
    public rtl::StaticWithArg<
    Instance, Reference<XComponentContext>, Singleton>
{};

extern "C" SAL_DLLPUBLIC_EXPORT XInterface * SAL_CALL
inco_niocs_test_BoolDataStore_get_implementation( XComponentContext *context,
						      Sequence<Any> const & )
{
    return cppu::acquire(static_cast<cppu::OWeakObject *>(
           Singleton::get(context).instance.get()));
}
