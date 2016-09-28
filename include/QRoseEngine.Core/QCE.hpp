#pragma once

#include <algorithm>
#include <functional>

using std::find;
using std::find_if;
using std::function;

// QRose Standard C++ library Collections Extensions

namespace QRose
{
	class QCE
	{
	public:
		template<typename TCollection, typename TEntity>
		static bool Contains(TCollection& collection, TEntity& entity)
		{
			return (std::find(collection.begin(), collection.end(), entity) != collection.end());
		}

		template<typename TCollection, typename TPredicate>
		static bool Any(TCollection& collection, TPredicate predicate)
		{
			return (std::find_if(collection.begin(), collection.end(), predicate) != collection.end());
		}

		template<typename TCollection, typename TPredicate>
		static bool RemoveIfContains(TCollection& collection, TPredicate predicate)
		{
			if (Any(collection, predicate))
			{
				collection.remove_if(predicate);
				return true;
			}
			else
			{
				return false;
			}
		}

		template<typename TEntity, typename TCollection, typename TPredicate>
		static TEntity& Find(TCollection& collection, TPredicate predicate)
		{
			if (!Any(collection, predicate))
			{
				throw std::runtime_error("collection contains no matching elements");
			}
			return *std::find_if(collection.begin(), collection.end(), predicate);
		}
	};
}