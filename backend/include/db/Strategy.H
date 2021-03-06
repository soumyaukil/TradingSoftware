#ifndef Strategy_H
#define Strategy_H

#include "Backend.H"
#include "Instrument.H"
#include "StrategyStatus.H"
#include "OrderType.H"
#include "quote/Side.H"

#include <shared/commands.h>

#include <odb/core.hxx>
#include <string>
#include <memory>
#include <boost/date_time/posix_time/posix_time.hpp>

namespace Algo
{
namespace Db
{
  #pragma db object table("Strategies")
  class Strategy
  {
    public:
      #pragma db value
      struct PrimaryKey
      {
        #pragma db column("StrategyId")
        unsigned long _strategyId;

        #pragma db column("BackendId")
        unsigned long _backendId;

        bool operator<(const struct PrimaryKey& rhs) const
        {
          return (_backendId < rhs._backendId && _strategyId < rhs._strategyId);
        }
      };

      Strategy();

      unsigned long strategyId() const;
      void setStrategyId(unsigned long strategyId);

      unsigned long backendId() const;
      void setBackendId(unsigned long backendId);

      int internalId() const;
      void setInternalId(int internalId);

      std::string uploadId() const;
      void setUploadId(const std::string& uploadId);

      unsigned long instrumentId() const;
      void setInstrumentId(unsigned long instrumentId);

      double tickSize() const;
      void setTickSize(double tickSize);

      AlgoType algoType() const;
      void setAlgoType(const AlgoType algoType);

      OrderMode mode() const;
      void setMode(const OrderMode mode);

      double previousClose() const;
      void setPreviousClose(double previousClose);

      double baseValue() const;
      void setBaseValue(double baseValue);

      double pointAPrice() const;
      void setPointAPrice(double pointAPrice);

      double pointAPercentage() const;
      void setPointAPercentage(double pointAPercentage);

      double pointBPrice() const;
      void setPointBPrice(double pointBPrice);

      double pointBPercentage() const;
      void setPointBPercentage(double pointBPercentage);

      double pointCPrice() const;
      void setPointCPrice(double pointCPrice);

      double pointCPercentage() const;
      void setPointCPercentage(double pointCPercentage);

      double CP1Price() const;
      void setCP1Price(double CP1Price);

      double CP1Percentage() const;
      void setCP1Percentage(double CP1Percentage);

      double CP2Price() const;
      void setCP2Price(double CP2Price);

      double CP2Percentage() const;
      void setCP2Percentage(double CP2Percentage);

      double ParentOrderPrice() const;
      void setParentOrderPrice(double parentOrderPrice);

      double profit() const;
      void setProfit(double profit);

      double profitPercentage() const;
      void setProfitPercentage(double profitPercentage);

      double loss() const;
      void setLoss(double loss);

      double lossPercentage() const;
      void setLossPercentage(double lossPercentage);

      double lossLimitPrice() const;
      void setLossLimitPrice(double lossLimitPrice);

      double trailing() const;
      void setTrailing(double trailing);

      double trailingPercentage() const;
      void setTrailingPercentage(double trailingPercentage);

      double tolerance() const;
      void setTolerance(double tolerance);

      boost::gregorian::date startDate() const;
      void setStartDate(boost::gregorian::date startDate);

      boost::posix_time::time_duration startTime() const;
      void setStartTime(boost::posix_time::time_duration startTime);

      boost::gregorian::date endDate() const;
      void setEndDate(boost::gregorian::date endDate);

      boost::posix_time::time_duration endTime() const;
      void setEndTime(boost::posix_time::time_duration endTime);

      boost::gregorian::date tExitDate() const;
      void setTExitDate(boost::gregorian::date tExitDate);

      boost::posix_time::time_duration tExitTime() const;
      void setTExitTime(boost::posix_time::time_duration tExitTime);

      double quantity() const;
      void setQuantity(double quantity);

      double cancelTicks() const;
      void setCancelTicks(double cancelTicks);

      const std::string& uploadName() const;
      void setUploadName(const std::string& uploadName);

      AlgoStrategyStatus strategyStatus() const;
      void setStrategyStatus(AlgoStrategyStatus strategyStatus);

     private:
      friend class odb::access;

      #pragma db id column("")
      struct PrimaryKey _strategyIdBakendId;
      // TODO: add lazy_ptr for Backend and getter method for it

      // generated by GUI
      #pragma db column("InternalId")
      unsigned long _internalId;

      #pragma db column("UploadId")
      std::string _uploadId;

      #pragma db column("InstrumentId") not_null
      unsigned long _instrumentId;

      #pragma db column("TickSize") type("DOUBLE PRECISION(20, 10)")
      double _tickSize;

      #pragma db column("AlgoType")
      AlgoType _algoType;

      #pragma db column("Side")
      OrderMode _mode;

      #pragma db column("PreviousClose") type("DOUBLE PRECISION(20, 10)")
      double _previousClose;

      #pragma db column("BaseValue") type("DOUBLE PRECISION(20, 10)")
      double _baseValue;

      #pragma db column("PointAPrice") type("DOUBLE PRECISION(20, 10)")
      double _pointAPrice;

      #pragma db column("PointAPercentage") type("DOUBLE PRECISION(20, 10)")
      double _pointAPercentage;

      #pragma db column("PointBPrice") type("DOUBLE PRECISION(20, 10)")
      double _pointBPrice;

      #pragma db column("PointBPercentage") type("DOUBLE PRECISION(20, 10)")
      double _pointBPercentage;

      #pragma db column("PointCPrice") type("DOUBLE PRECISION(20, 10)")
      double _pointCPrice;

      #pragma db column("PointCPercentage") type("DOUBLE PRECISION(20, 10)")
      double _pointCPercentage;

      #pragma db column("CP1Price") type("DOUBLE PRECISION(20, 10)")
      double _CP1Price;

      #pragma db column("CP1Percentage") type("DOUBLE PRECISION(20, 10)")
      double _CP1Percentage;

      #pragma db column("CP2Price") type("DOUBLE PRECISION(20, 10)")
      double _CP2Price;

      #pragma db column("CP2Percentage") type("DOUBLE PRECISION(20, 10)")
      double _CP2Percentage;

      #pragma db column("ParentOrderPrice") type("DOUBLE PRECISION(20, 10)")
      double _parentOrderPrice;

      #pragma db column("Profit") type("DOUBLE PRECISION(20, 10)")
      double _profit;

      #pragma db column("ProfitPercentage") type("DOUBLE PRECISION(20, 10)")
      double _profitPercentage;

      #pragma db column("Loss") type("DOUBLE PRECISION(20, 10)")
      double _loss;

      #pragma db column("LossPercentage") type("DOUBLE PRECISION(20, 10)")
      double _lossPercentage;

      #pragma db column("LossLimitPrice") type("DOUBLE PRECISION(20, 10)")
      double _lossLimitPrice;

      #pragma db column("Trailing") type("DOUBLE PRECISION(20, 10)")
      double _trailing;

      #pragma db column("TrailingPercentage") type("DOUBLE PRECISION(20, 10)")
      double _trailingPercentage;

      #pragma db column("Tolerance") type("DOUBLE PRECISION(20, 10)")
      double _tolerance;

      #pragma db type("DATE") column("StartDate")
      boost::gregorian::date _startDate;

      #pragma db type("TIME") column("StartTime")
      boost::posix_time::time_duration _startTime;

      #pragma db type("DATE") column("EndDate")
      boost::gregorian::date _endDate;

      #pragma db type("TIME") column("EndTime")
      boost::posix_time::time_duration _endTime;

      #pragma db type("DATE") column("TExitDate")
      boost::gregorian::date _tExitDate;

      #pragma db type("TIME") column("TExitTime")
      boost::posix_time::time_duration _tExitTime;

      #pragma db column("Quantity") type("DOUBLE PRECISION(20, 10)")
      double _quantity;

      #pragma db column("CancelTicks")
      int _cancelTicks;

      #pragma db column("UploadName")
      std::string _uploadName;

      #pragma db column("StrategyStatus") not_null
      AlgoStrategyStatus _strategyStatus;
  };
} // namespace Db
} // namespace Algo

#endif // Strategy_H
