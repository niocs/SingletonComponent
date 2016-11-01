#ifndef INCO_NIOCS_TEST_SINGLETONCOMPONENT_HXX
#define INCO_NIOCS_TEST_SINGLETONCOMPONENT_HXX

#include <cppuhelper/implbase2.hxx>
#include <inco/niocs/test/XBoolDataStore.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>

#define IMPLEMENTATION_NAME "inco.niocs.test.BoolDataStoreImpl"

class BoolDataStoreImpl : public cppu::WeakImplHelper2
<
    com::sun::star::lang::XServiceInfo,
    inco::niocs::test::XBoolDataStore
>
{
    sal_Bool bData;
public:
    inline BoolDataStoreImpl() throw ()
            : bData(false)
    {}
    virtual ~BoolDataStoreImpl() {}

    // XBoolDataStore methods
    virtual sal_Bool SAL_CALL getBool() { return bData; }
    virtual void     SAL_CALL setBool( const sal_Bool bSet ) { bData = bSet; }
    
    // XServiceInfo methods
    virtual ::rtl::OUString SAL_CALL getImplementationName()
        throw (::com::sun::star::uno::RuntimeException);
    virtual sal_Bool SAL_CALL supportsService( const ::rtl::OUString& aServiceName )
        throw (::com::sun::star::uno::RuntimeException);
    virtual ::com::sun::star::uno::Sequence< ::rtl::OUString > SAL_CALL getSupportedServiceNames()
        throw (::com::sun::star::uno::RuntimeException);
};


#endif
