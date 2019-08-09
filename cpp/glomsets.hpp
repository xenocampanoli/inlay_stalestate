/* glomsets.hpp
12345678901234567890123456789012345678901234567890123456789012345678901234567890
 */
#pragma once

#include "env.hpp"

namespace Inlay {

	class GlomBase { // State Changing Object!!

		public:

		inline std::string getIdentifier() {
			std::string b = _get_Identifier(SMatchO);
			return b;
		}
		inline std::string getIdPattern() {
			std::string b = _get_Id_Pattern(SMatchO);
			return b;
		}

		inline bool itemFound() {
			// Look for standard smatch method to use. TBD
			if ( ! SMatchO.ready() ) return false;
			if ( SMatchO.empty() ) return false;
			return true;
		}

		GlomBase(const std::string& tagPattern,const std::string& targetText);

		void replaceFoundIdentifier(std::string& targetText, std::string& replacementString);

		private:

		const std::string Identifier; // Json Key within the interpolation pattern to be processed.
		const std::string IdPattern;  // The actual interpolation pattern to be processed.
		const std::smatch SMatchO;

		const std::smatch findFirst(const std::string& tagPattern, const std::string& targetText);

		virtual const std::string _adjust_Replacement_String(const std::string& replacementString,const std::smatch& sMO) = 0;
		virtual const std::string _get_Identifier(const std::smatch& sMO) = 0;
		virtual const std::string _get_Id_Pattern(const std::smatch& sMO) = 0;

	};

	class MustSubMoldGlom: public GlomBase {
		public:
		MustSubMoldGlom(const std::string& targetText);
		private:
		const std::string _adjust_Replacement_String(const std::string& replacementString,const std::smatch& sMO) override;
		const std::string _get_Identifier(const std::smatch& sMO) override;
		const std::string _get_Id_Pattern(const std::smatch& sMO) override;
	};

	class OptionalGlom: public GlomBase {
		public:
		OptionalGlom(const std::string& targetText);
		private:
		const std::string _adjust_Replacement_String(const std::string& replacementString,const std::smatch& sMO) override;
		const std::string _get_Identifier(const std::smatch& sMO) override;
		const std::string _get_Id_Pattern(const std::smatch& sMO) override;
	};

	class RequiredGlom: public GlomBase {
		public:
		RequiredGlom(const std::string& targetText);
		private:
		const std::string _adjust_Replacement_String(const std::string& replacementString,const std::smatch& sMO) override;
		const std::string _get_Identifier(const std::smatch& sMO) override;
		const std::string _get_Id_Pattern(const std::smatch& sMO) override;
	};

} // End of namespace Inlay

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of glomsets.hpp
